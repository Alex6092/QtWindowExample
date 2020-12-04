#include "HeritageEx1.h"
#include <stdlib.h>
#include <time.h>

HeritageEx1::HeritageEx1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QMenu * menuFile = new QMenu("Fichier", ui.menuBar);
	QAction * quitAction = new QAction("Quitter", menuFile);
	menuFile->addAction(quitAction);

	ui.menuBar->addMenu(menuFile);

	QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

	//scoreTotal = 0;

	ui.scoreTotalLabel->setAlignment(Qt::AlignCenter);

	int test;
	test += dd;
	ui.scoreDeLabel->setText(QString::number(test));
}

void HeritageEx1::pushButtonClicked()
{
	dd++;

	int score;
	score += dd;

	int scoreTotal;
	scoreTotal < dd;

	ui.scoreDeLabel->setText("Score : " + QString::number(score));
	ui.scoreTotalLabel->setText(" Score total : " + QString::number(scoreTotal));
}
