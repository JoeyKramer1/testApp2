#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QStringList"
#include "qpixmap.h"
#include "QVector"
#include <QDebug>

#define BOARDSIZE 15
#define NUMBEROFTILES 7


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString test = "Testing";
}




MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


 //   qDebug() << QCoreApplication::applicationDirPath ();

    QVector<QString> ImageLocationsStringList;
    {
    ImageLocationsStringList.append(":/pngs/pngs/daVinci.png"); //0
    ImageLocationsStringList.append(":/pngs/pngs/daVinciDiamond.png"); //1
    ImageLocationsStringList.append(":/pngs/pngs/Emerald.png"); //2
    ImageLocationsStringList.append(":/pngs/pngs/Female.png"); //3
    ImageLocationsStringList.append(":/pngs/pngs/MonaLisa.png"); //4
    ImageLocationsStringList.append(":/pngs/pngs/Ruby.png"); //5
    ImageLocationsStringList.append(":/pngs/pngs/Topaz.png"); //6
    }



    QVector<QLabel*> my_labelsr1; //This is repopulating the Vector everytime, not sure where to put this so it populates in begining tho. Putting it in constructor,
    {
    my_labelsr1.push_back(ui->One_One);
    my_labelsr1.push_back(ui->One_Two);
    my_labelsr1.push_back(ui->One_Three);
    my_labelsr1.push_back(ui->One_Four);
    my_labelsr1.push_back(ui->One_Five);
    };
    QVector<QLabel*> my_labelsr2;
    {
    my_labelsr2.push_back(ui->Two_One);
    my_labelsr2.push_back(ui->Two_Two);
    my_labelsr2.push_back(ui->Two_Three);
    my_labelsr2.push_back(ui->Two_Four);
    my_labelsr2.push_back(ui->Two_Five);
    }
    QVector<QLabel*> my_labelsr3;
    {
    my_labelsr3.push_back(ui->Three_One);
    my_labelsr3.push_back(ui->Three_Two);
    my_labelsr3.push_back(ui->Three_Three);
    my_labelsr3.push_back(ui->Three_Four);
    my_labelsr3.push_back(ui->Three_Five);
    }
    QVector<QVector <QLabel* > > RowsAndColumns;
    {
    RowsAndColumns.push_back(my_labelsr1);
    RowsAndColumns.push_back(my_labelsr2);
    RowsAndColumns.push_back(my_labelsr3);
    }


    QVector <int> Tiles;

    for(int i=0; i<RowsAndColumns.size();i++)
    {
        for(int j=0; j<RowsAndColumns[i].size();j++)
        {
            int temp = qrand()%NUMBEROFTILES;
            RowsAndColumns[i][j]->setPixmap(ImageLocationsStringList[temp]);
            Tiles.append(temp);
        }

    }

    //check for horizontal matches

    if(Tiles[0] == Tiles[1] && Tiles[1]==Tiles[2])
    {
        if(Tiles[2] == Tiles[3])
        {
            if(Tiles[3] == Tiles[4])
            {
                qDebug() << "Congrats you got a win on the top-line, five in a row";
                return;

            }
            qDebug() << "Congrats you got a win on the top-line, four in a row";
            return;

        }
        qDebug() << "Congrats you got a win on the top-line, three in a row";
    }
    if(Tiles[5] == Tiles[6] && Tiles[6]==Tiles[7])
    {
        if(Tiles[7] == Tiles[8])
        {
            if(Tiles[8] == Tiles[9])
            {
                qDebug() << "Congrats you got a win on the middle-line, five in a row";
                return;

            }
            qDebug() << "Congrats you got a win on the middle-line, four in a row";
            return;

        }
        qDebug() << "Congrats you got a win on the middle-line, three in a row";
    }

    if(Tiles[10] == Tiles[11] && Tiles[11]==Tiles[12])
    {
        if(Tiles[12] == Tiles[13])
        {
            if(Tiles[13] == Tiles[14])
            {
                qDebug() << "Congrats you got a win on the bottom-line, five in a row";
                return;

            }
            qDebug() << "Congrats you got a win on the bottom-line, four in a row";
            return;
        }
        qDebug() << "Congrats you got a win on the bottom-line, three in a row";
    }


    //Check for matches

}

