#include "HeritageEx1.h"

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

	srand(time(NULL));
	scoreTotal = 0;

	ui.scoreTotalLabel->setAlignment(Qt::AlignCenter);
}

void HeritageEx1::pushButtonClicked()
{
	int scoreDe = rand() % 6 + 1;
	scoreTotal += scoreDe;

	ui.scoreDeLabel->setText("Score : " + QString::number(scoreDe));
	ui.scoreTotalLabel->setText(" Score total : " + QString::number(scoreTotal));
}
