#include "graphe.h"
#include "mainwindow.h"
#include "arete.h"
#include "sommet.h"
#include <math.h>
#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <queue>
#include <iostream>
QList <Arete *> reseau_nv;
using namespace std;
Graphe::Graphe(MainWindow *parent, qreal w, qreal h)
    : window(parent),sommet(nullptr),sommet1(nullptr),sommet2(nullptr)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0,w,h);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
}
Graphe::Graphe(int V)
{
    adj= new std::list<int>[V];

}
void Graphe::save(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly)){
        QMessageBox::warning(this,"warning","file not open");
        return;
    }
    QDataStream out(&file);
    out << sommets.size();
    foreach (Sommet * sommet, sommets) {
        out<<sommet->pos().x();
        out<<sommet->pos().y();
        out<<sommet->getId();
    }
    out<<aretes.size();
    foreach (Arete *arete, aretes) {
        out <<sommets.indexOf(arete->sourceNode());
        out <<sommets.indexOf(arete->destNode());
        out << arete->getpoids();
    }
}
void Graphe::open(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly)){
        QMessageBox::warning(this,"warning","file not open");
        return;
    }
    QDataStream in(&file);
    int n;
    in >>n;
    for(int i=0;i<n;i++){
        qreal x,y;
        int num;
        in >> x >>y;
        in >>num;
        addNode(num,x,y);
    }
    in >>n;
    for(int i=0;i<n;i++){
        int a,b;
        double c;
        in >> a >>b>>c;

        addEdgeOp(sommets[a],sommets[b],c);
    }
}

void Graphe::select(Sommet *sommet)
{
    if(selectFun){
        if(this->sommet==nullptr){
            sommet->setPenWidth(2);
        }
        else{
            if(this->sommet==sommet&&this->sommet->getPenWidth()==2)
                sommet->setPenWidth(1);
            else{
                this->sommet->setPenWidth(1);
                sommet->setPenWidth(2);

            }
        }
        this->sommet=sommet;

    }
}

void Graphe::addNode(qreal sommet_id, qreal x, qreal y)
{

    Sommet *sommet=new Sommet(this,sommet_id);
    sommet->setId(getNodeNum());
    sommet->setPos(x,y);
    scene->addItem(sommet);
    sommets<<sommet;
    som_id.append(sommet_id);
}

void Graphe::removeNode(qreal sommet_id){
    som_id.removeOne(sommet_id);
    scene->removeItem(sommet);

}
void Graphe::setSceneRect(qreal w, qreal h)
{
    scene->setSceneRect(0, 0,w,h);
}

void Graphe::setNodeToAddEdge(Sommet *sommet, int no)
{
    if(no==1){
        sommet1=sommet;
    }
    else{
        sommet2=sommet;
    }
    sommet->click();
}
void Graphe::addEdge(Sommet *sommet1, Sommet *sommet2)
{
    setNodeToAddEdge(sommet1, 1);
    setNodeToAddEdge(sommet2, 2);
    addEdge();
}

void Graphe::addEdgeOp(Sommet *a, Sommet *b, int c)
{    setNodeToAddEdge(a, 1);
     setNodeToAddEdge(b, 2);
     addedgeOpen(c);

}

void Graphe::addedgeOpen(int a)
{
    bool checkExistance=false;
      bool already_connected=false;
      for(const Arete *arete : sommet1->Aretes()){
          if(arete->destNode()==sommet2){
              already_connected=true;
              break;
          }
      }
      for(int i=0;i<aretes.size();i++){
          if((aretes[i]->sourceNode()==sommet1 ||aretes[i]->sourceNode()==sommet2) &&( aretes[i]->destNode()==sommet2|| aretes[i]->destNode()==sommet1) ){
             checkExistance=true;
          }
      }
      if(!(sommet1==sommet2||already_connected)){

          if(checkExistance==false){
              Arete *arete=new Arete(sommet1, sommet2,this,true );
              scene->addItem(arete);
              arete->poids=a;
              aretes << arete;
              qInfo()<<" nexiste pas ";
          }

      }

      sommet1->click();
      sommet2->click();
      sommet1=NULL;
      sommet2=NULL;
      update();
}


void Graphe::addEdge()
{   bool checkExistance=false;
    bool already_connected=false;
    for(const Arete *arete : sommet1->Aretes()){
        if(arete->destNode()==sommet2){
            already_connected=true;
            break;
        }
    }
    for(int i=0;i<aretes.size();i++){
        if((aretes[i]->sourceNode()==sommet1 ||aretes[i]->sourceNode()==sommet2) &&( aretes[i]->destNode()==sommet2|| aretes[i]->destNode()==sommet1) ){
           checkExistance=true;
        }
    }
    if(!(sommet1==sommet2||already_connected)){

        if(checkExistance==false){
            Arete *arete=new Arete(sommet1, sommet2,this );
            scene->addItem(arete);
            aretes << arete;
            qInfo()<<" nexiste pas ";
        }

    }

    sommet1->click();
    sommet2->click();
    sommet1=NULL;
    sommet2=NULL;
    update();
}

bool Graphe::areteExist(int a , int b){
    bool already_exist=false;
    for (int i=0;i<aretes.size();i++) {
        if(((aretes[i]->sourceNode()->getId()==a) && (aretes[i]->destNode()->getId()==b)) ||
                ((aretes[i]->sourceNode()->getId()==b) && (aretes[i]->destNode()->getId()==a))){
           already_exist=true;
           break;
        }

    }
    if(already_exist){return true;}
    else return false;
}
void Graphe::generateur(int som, int are){
    //appel a la fonction de reset() pour eviter plsrs graphe au meme temps
    reset();
    som=window->getsom();
    are=window->getare();
    int id=-1;
    if(are>(som*(som-1))/2){are=(som*(som-1))/2;
        qInfo()<<"le nombre d'arrete est "<<are;}
       for(int i=0 ;i<som;i++){
          int x=600;
          int y=300;
          int a=qrand() % (x-120) +420 ;
          int b=-(qrand() % (y-50) )+320 ;
          id++;
           sommet = new Sommet(this, id);
           sommet->setPos(a,b);
           scene->addItem(sommet);
           sommets.push_back(sommet);
           som_id.append(id);
       }
      do{
           int a;
           int b;
           do{
            a=rand() % sommets.size() + 0;
            b=rand() % sommets.size() + 0 ;}
           while(a==b);
           //bool already_connected=false;
           if(!areteExist(a,b)){
           Arete *arete=new Arete(getNode(a),getNode(b),this,true);
            aretes.push_back(arete);

          scene->addItem(arete);
          arete->poids = qrand()%100 + 1;
           are--;
       }
}while(are!=0);}

void Graphe::removeItem(QGraphicsItem * item){
    scene->removeItem(item);
    update();
}

void Graphe::selectSlot(bool b)
{

    selectFun=b;
}

void Graphe::addNodeSlot(bool b)
{
    addNodeFun=b;
}

void Graphe::addEdgeSlot(bool b)
{
    addEdgeFun=b;
}

void Graphe::eraserSlot(bool b)
{
    EraserFun=b;
}


void Graphe::mousePressEvent(QMouseEvent *event)
{

    if(addNodeFun){
        int x=getNodeNum();
        Sommet *sommet=new Sommet(this,x);
        sommet->setPos(mapToScene(event->pos()));
        sommets<<sommet;
        qInfo()<<sommets.size();
        scene->addItem(sommet);
    }
    QGraphicsView::mousePressEvent(event);
    scene->update();
    viewport()->update();


}

Sommet *Graphe::getNode(qreal sommet_id)
{
   for(int i=0;i<sommets.size();i++){
       if(sommets[i]->getId()==sommet_id){
           return sommets[i];
       }
   }

}

void Graphe::setNode(Sommet *value)
{
    sommet = value;
}

QPair<Sommet *, QList<Sommet *> > Graphe::getlistdadja(Sommet* sommetx)
{
    QPair<Sommet*,QList<Sommet*>> adja;
    int U=aretes.size();
        for(int j=0;j<U;j++){
            if(sommetx==(aretes[j]->sourceNode())){
                adja.first=aretes[j]->destNode();
                QList<Sommet*> itsadja;
                itsadja.append(aretes[j]->destNode());
                adja.second=itsadja;
            }
        }
    return adja;
}

void Graphe::removeEdge(Arete *arete)
{
    aretes.removeOne(arete);
}


void Graphe::reset(){
    //vider les garphics dans la scene
   scene->clear();
    //vider la liste des sommets
   sommets.clear();
    //vider la liste des aretes
   aretes.clear();
    //vider la liste des sommets de graphe genere par le generateur automatique
    //this->sommetrd.clear();
    //vider la liste des aretes de graphe genere par le generateur automatique
    //this->areterd.clear();
  som_id.clear();
  reseau_nv.clear();
  termoblig.clear();
  tree.clear();

}

bool Graphe::connexe()
{
        int n =sommets.size();
        std::queue<int> q;
        std::vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int adj = 0; adj < n; adj++) {
                for(int j=0;j<aretes.size();j++){
                if ((checkcon(getNode(v),getNode(adj)) || checkcon(getNode(adj),getNode(v))) && !visited[adj])
                {
                    visited[adj] = true;
                    q.push(adj);
                }
                }
            }
        }
        for (int i = 0; i < (int)visited.size(); i++)
            if (visited[i] == false)
                return false;
        return true;
}

bool Graphe::checkcon(Sommet *som1, Sommet *som2)
{
    bool already_connected=false;
    for(const Arete *arete : som1->Aretes()){
        if(arete->destNode()==som2){
            already_connected=true;

            return true;
        }
}
    return false;
}
bool Graphe::sortt(Arete *are1, Arete *are2)
{
    return are1->getpoids()<are2->getpoids();
}
int Graphe::find(int r) {
    return (parent[r] == r) ? r : find(parent[r]);
}
QList<Arete*> Graphe::kruskal_mst() {
    QList<Arete*> ares;
    QList<Arete*>colo;
    ares=aretes;
        std::sort(ares.begin(),ares.end(),sortt);
         int cnt = 0, tcost = 0, u, v;
        for (int j= 0; j < sommets.size(); j++){
            parent[j] = j;}
        for (int i = 0; i < aretes.size(); i++) {
            u = find(ares[i]->sourceNode()->getId());
            v = find(ares[i]->destNode()->getId());
            if (u != v) {
                parent[u] = v;
                cnt++;
                tcost += ares[i]->getpoids();
                colo.append(ares[i]);
                if (cnt == sommets.size()-1) break;
            }

        }
       printf("\nminimum cost: %d\n", tcost);
   return colo;
}
int Graphe::display()
{
    QList<Arete*> pds=kruskal_mst();
    int s=0;
    for(int i =0;i<pds.size();i++){
        s=s+pds[i]->getpoids();
    }
    return s;
}

bool Graphe::hasthisedge(int a, int b)
{
    const int size = aretes.size();
    for(int i=0; i<size; ++i)
    {
        if (((aretes[i]->sourceNode()->getId()==a) && (aretes[i]->destNode()->getId()==b)) ||
                ((aretes[i]->sourceNode()->getId()==b) && (aretes[i]->destNode()->getId()==a)))
        {
            return true;
        }
    }
    return false;
}

int Graphe::getedgepoids(int a, int b)
{
    for(int i=0;i<aretes.size();i++){
          if((aretes[i]->sourceNode()->getId()==a) && (aretes[i]->destNode()->getId()==b)){
              return aretes[i]->getpoids();
          }
       }
}

Arete *Graphe::getarete(int a)
{
    for (int i=0;i<aretes.size();i++){
        if (i==a)
            return aretes[a];
    }
}
Arete *Graphe::getaretesd(int a, int b)
{
    for (int i=0;i<aretes.size();i++) {
        if(((aretes[i]->sourceNode()->getId()==a) && (aretes[i]->destNode()->getId()==b)) ||
                ((aretes[i]->sourceNode()->getId()==b) && (aretes[i]->destNode()->getId()==a))){
            return aretes[i];
        }
    }
}
bool Graphe::hasthisedge(Sommet * a, Sommet * b)
{
    QList<Arete *>::iterator i;
    for (i=aretes.begin();i<aretes.end();i++){
        if (checkcon(a,b) || checkcon(b,a)){
            return  true;
        }
    }
    return  false ;
}
int Graphe::getedgepoids(Sommet * a, Sommet * b)
{

    QList<Arete *>::iterator i;
        for(i=aretes.begin(); i!=aretes.end(); i++){
            if( ( (*i)->sourceNode()==a && (*i)->destNode()==b )|| ( (*i)->sourceNode()==b && (*i)->destNode()==a ) ){
                return (*i)->getpoids();
            }

        }
   // }
}
QList<Sommet *> Graphe::dijkstra(Sommet *source, Sommet *goal)
{
    QList<Sommet *> path;

        std::priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

        SIZE=sommets.size();
        vector<int> dist(SIZE , oo);
        vector<int> chemin(SIZE , -1);
        dist[source->getId()]=0;
        chemin[source->getId()]=source->getId();

        pq.push(make_pair(0,source));


        while(!pq.empty()){

                Sommet * u = pq.top().second;
                qInfo()<<" u =  "<<pq.top().second->getId();
                qInfo()<<"distance de u = "<<pq.top().first;
                pq.pop();

                QList<Sommet *> Adj=findAdj(u);
                QList<Sommet *>::iterator it;
                qInfo()<<"adj = "<<Adj.size();
                for(it=Adj.begin(); it<Adj.end(); it++){

                    Sommet * v=(*it);
                    qInfo()<<"v = "<<v->getId();
                    int weight=getedgepoids(u,(*it));
                    qInfo()<<"weight = " <<weight;

                    if (dist[v->getId()] > dist[u->getId()] + weight){

                        dist[v->getId()] = dist[u->getId()] + weight;
                        pq.push(make_pair(dist[v->getId()], v));

                            chemin[v->getId()]= u->getId();
                        qInfo()<<"update dist de "<<v->getId() <<" =  "<<dist[v->getId()];
                    }
                }
        }
        int courant=goal->getId();
        while(courant!=chemin[courant]){
            Sommet * s=GetSomById(courant);
            path.append(s);
            courant=chemin[courant];
        }
        path.append(source);
        for(int i=0; i<dist.size(); i++ ){
            qInfo()<<"dist = "<<i << "est "<<dist[i];
        }
        for(int i=0; i<chemin.size(); i++ ){
            qInfo()<<"parent de "<<i << "est "<<chemin[i];
        }
        for(int i=0; i<path.size(); i++ ){
            qInfo()<<"path "<<i << "est "<<path.at(i)->getId();
        }
 qInfo()<<"path size = "<<path.size();
return path;
}
QList<Sommet *> Graphe::findAdj(Sommet * cible)
{
      QList<Sommet *> Adj;
      QList<Sommet *>::iterator i;
      for(i=sommets.begin(); i!=sommets.end(); ++i){
          if( hasthisedge(cible, (*i) ) && (*i)!=cible ){
              Adj.append((*i));
          }
      }
      return Adj;
}
Sommet * Graphe::GetSomById(int id)
{
    QList<Sommet*>::iterator i;
    for(i=sommets.begin();i!=sommets.end();i++){
        if((*i)->getId()==id){
            return *i;
        }
    }
}
Arete *Graphe::GetArete(Sommet * a, Sommet * b)
{
    QList<Arete *>::iterator i;
    for (i=aretes.begin();i<aretes.end();i++){
        if ( checkcon(a,b) || checkcon(b,a) ){
            return (*i);
        }
    }
    return  nullptr;
}

void Graphe::reseau(QList<Sommet *> term){
    bool exist=false;
  QList <Arete *> copie;
    int n=term.size();
 for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        QList <Sommet *> copieOfdji= dijkstra(term[i],term[j]);
          for(int k=0;k<copieOfdji.size()-1;k++){
                Arete* test =getaretesd(copieOfdji[k+1]->getId(),copieOfdji[k]->getId());
                if(reseau_nv.size()==0){
                    reseau_nv.push_back(test);
                }
for (int e=0;e<reseau_nv.size();e++) {
      exist=false;
 if((test->sourceNode()->getId()==reseau_nv[e]->sourceNode()->getId() && test->destNode()->getId()==reseau_nv[e]->destNode()->getId()) ||
(test->sourceNode()->getId()==reseau_nv[e]->destNode()->getId() && test->destNode()->getId()==reseau_nv[e]->sourceNode()->getId())){
                      exist=true;
                      break;
                  }
              }
              if(!exist){
            reseau_nv.push_back(test);}
          }
    }
        for(int i=0;i< reseau_nv.size();i++){
            reseau_nv[i]->newcolo=true;
        }
        update();
}
for (int h=0;h<reseau_nv.size();h++) {
qInfo()<<"l arrete numero "<<h<<" dans le reseau : son dest est "<<reseau_nv[h]->destNode()->getId()<<" son src est "<<reseau_nv[h]->sourceNode()->getId();
    }
}
QList<Sommet *> Graphe ::fcttermoblig(){
    return termoblig;
}
void Graphe::removeedgenotcol(){
    int b=aretes.size();
    for(int i=0;i<b;i++){
        if(aretes[i]->newcolo==false){
             removeItem(aretes[i]);
              aretes.removeAt(i);
              i--;
              b--;
        }
    }
}
void Graphe::removeedgenotcol2(){
    int b=aretes.size();
    for(int i=0;i<b;i++){
        if(aretes[i]->newcolo==true){
             removeItem(aretes[i]);
              aretes.removeAt(i);
              i--;
              b--;
        }
    }
}
QList<Arete *> Graphe::steinerTree(){
    int b=reseau_nv.size();
    for(int i=0;i<b;i++){
        if(reseau_nv[i]->coloration==true){
             tree.push_back(reseau_nv[i]);

        }
    }
    return tree;
}
void Graphe::degre1(){
    for(int i=0;i<aretes.size();i++){
        aretes[i]->sourceNode()->degre++;
        aretes[i]->destNode()->degre++;
    }
    int size=sommets.size();
    for(int e=0;e<size;e++){
        if(sommets[e]->degre==1 && sommets[e]->ter==false){
            int size2=reseau_nv.size();
     for(int i=0;i<size2;i++){
         if(reseau_nv[i]->sourceNode()->getId()==sommets[e]->getId() ||reseau_nv[i]->destNode()->getId()==sommets[e]->getId() ){
                 removeItem(reseau_nv[i]);
                 reseau_nv.removeAt(i);
                  update();
                  i--;
                   size2--;
                            }
                        }
            update();
        }
    }
}
