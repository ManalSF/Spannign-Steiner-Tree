#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sommet.h"
#include "arete.h"
#include "graphe.h"
#include <QToolBar>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QPushButton>
#include <QTextEdit>
#include <iostream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    widget = new Graphe(this,1024,512);
    ui->setupUi(this);
    setWindowTitle("ArbreC");
    ui->graphLayout->addWidget(widget);
    setWindowIcon(QIcon(":/Logo/logo.bmp"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::getsom(){
    return ui->som->value();
}
int MainWindow::getare(){
    return ui->are->value();
}

void MainWindow::colo()
{
    QList<Arete*> temcolo=widget->kruskal_mst();
    for(int i=0;i<temcolo.size();i++){
        temcolo[i]->newcolo=false;
        temcolo[i]->coloration=true;
        temcolo[i]->update();
    }
    update();

}

/*void MainWindow::colo1()
{
    int start=QInputDialog::getInt(this,tr("input"),tr("Entrer le sommet source"));
    int goal=QInputDialog::getInt(this,tr("input"),tr("Entrer le sommet destination"));
    this->start=start;
    this->goal=goal;
   // QList<int> temcolo=widget->dijkstraone(start,goal);
    QList<Arete*> temcolo2;
    for (int j=0;j<temcolo.size()-1;j++){
        int source =temcolo[j];
        int destination=temcolo[j+1];
         temcolo2.append(widget->getaretesd(source,destination));

    }
    for(int i=0;i<temcolo2.size();i++){
        temcolo2[i]->coloration=true;
    }
    update();

}*/

void MainWindow::on_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"","",tr("Graph (*.graph)"));
    widget->open(fileName);
}

void MainWindow::on_save_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"","",tr("Graph (*.graph)"));
    widget->save(fileName);

}





void MainWindow::on_pushButton_2_clicked()
{
    widget->Graphe::addNodeSlot(true);
    widget->Graphe::addEdgeSlot(false);
    widget->Graphe::eraserSlot(false);
    widget->Graphe::selectSlot(false);
     widget->color=false;
}

void MainWindow::on_pushButton_3_clicked()
{
    widget->Graphe::addNodeSlot(false);
    widget->Graphe::addEdgeSlot(true);
    widget->Graphe::eraserSlot(false);
    widget->Graphe::selectSlot(false);
     widget->color=false;
}

void MainWindow::on_pushButton_clicked()
{
    widget->Graphe::addNodeSlot(false);
    widget->Graphe::addEdgeSlot(false);
    widget->Graphe::eraserSlot(true);
    widget->Graphe::selectSlot(false);
     widget->color=false;
}

void MainWindow::on_pushButton_4_clicked()
{
    widget->Graphe::addNodeSlot(false);
    widget->Graphe::addEdgeSlot(false);
    widget->Graphe::eraserSlot(false);
    widget->Graphe::selectSlot(true);
     widget->color=false;
}

void MainWindow::on_Generate_clicked()
{
    int som=getsom();
    int are=getare();
    widget->generateur(som,are);
}

void MainWindow::on_reset_clicked()
{ ui->textEdit->clear();

    widget->reset();

}
void MainWindow::on_pushButton_7_clicked()
{


        this->colo();
        int f= widget->display();
        QList<Arete*> tem=widget->kruskal_mst();
        for (int k=0;k<tem.size();k++){
            std::cout<< tem[k]->sourceNode()->getId() <<"-"<< tem[k]->destNode()->getId()<<":"<<tem[k]->getpoids()<<std::endl;
            ui->textEdit->insertPlainText(QString::number(tem[k]->sourceNode()->getId()));
            ui->textEdit->insertPlainText("-");
            ui->textEdit->insertPlainText(QString::number(tem[k]->destNode()->getId()));
            ui->textEdit->insertPlainText(":");
            ui->textEdit->insertPlainText(QString::number(tem[k]->getpoids()));
            ui->textEdit->insertPlainText("\n");
        }
        ui->textEdit->insertPlainText("le poids minimal est ");
        ui->textEdit->insertPlainText(QString::number(f));

        widget->Graphe::removeedgenotcol2();
        widget->Graphe::degre1();


}
void MainWindow::on_pushButton_5_clicked()
{
    widget->Graphe::addNodeSlot(false);
    widget->Graphe::addEdgeSlot(false);
    widget->Graphe::eraserSlot(false);
    widget->Graphe::selectSlot(false);
   widget->color=true;
   qInfo()<<widget->color;
}
void MainWindow::on_pushButton_9_clicked()
{
    ui->textEdit->clear();
    if (widget->connexe()==false){
    QMessageBox::information(this, "Erreur", "Votre graphe n'est pas connexe.") ;
    }
else{
    widget->Graphe::reseau(widget->Graphe::fcttermoblig());
    widget->Graphe::removeedgenotcol();
    on_pushButton_7_clicked();
    QList<Arete *> tem= widget->Graphe::steinerTree();
     int f=0;
     ui->textEdit->clear();
     for (int k=0;k< tem.size();k++){
         std::cout<< tem[k]->sourceNode()->getId() <<"-"<< tem[k]->destNode()->getId()<<":"<<tem[k]->getpoids()<<std::endl;
         ui->textEdit->insertPlainText(QString::number(tem[k]->sourceNode()->getId()));
         ui->textEdit->insertPlainText("-");
         ui->textEdit->insertPlainText(QString::number(tem[k]->destNode()->getId()));
         ui->textEdit->insertPlainText(":");
         ui->textEdit->insertPlainText(QString::number(tem[k]->getpoids()));
         ui->textEdit->insertPlainText("\n");
         f+=tem[k]->getpoids();
     }

     ui->textEdit->insertPlainText("le poids minimal est ");
     ui->textEdit->insertPlainText(QString::number(f));

}}

void MainWindow::on_pushButton_8_clicked()
{     ui->textEdit->clear();
      if (widget->connexe()==false){
      QMessageBox::information(this, "Erreur", "Votre graphe n'est pas connexe.") ;
      }
  else{
    int start=QInputDialog::getInt(this,tr("input"),tr("Entrer le sommet source"));
    int goal=QInputDialog::getInt(this,tr("input"),tr("Entrer le sommet destination"));
    QList<Sommet*> djisk;
    djisk=widget->Graphe::dijkstra(widget->Graphe::getNode(start),widget->Graphe::getNode(goal));
    QList<Arete*> temcolo2;
    for(int i=0;i<djisk.size();i++){
        qInfo()<<"shortest path sommet numero "<<i<<" son id est "<<djisk[i]->getId();

    }
    for(int f=0;f<(djisk.size()-1);f++){

        temcolo2.push_back(widget->getaretesd(djisk[f]->getId(),djisk[f+1]->getId()));
        qInfo()<<"jai exucuté literation numero "<<f;
    }

    for(int i=0;i<temcolo2.size();i++){
        temcolo2[i]->coloration=true;
    }
    update();
}}

void MainWindow::on_pushButton_10_clicked()
{

    widget->Graphe::removeedgenotcol();


}

void MainWindow::on_pushButton_11_clicked()
{
    widget->Graphe::removeedgenotcol2();
}
