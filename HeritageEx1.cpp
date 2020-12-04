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

	QMenu * menuChoisir = new QMenu("Choisir", ui.menuBar);
	QList<QAction*> actions;
	actions.push_back(new QAction("De", menuChoisir));
	actions.push_back(new QAction("De histo", menuChoisir));
	menuChoisir->addActions(actions);

	ui.menuBar->addMenu(menuChoisir);

	QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

	//scoreTotal = 0;

	ui.scoreTotalLabel->setAlignment(Qt::AlignCenter);

	int test;
	test += dd;
	ui.scoreDeLabel->setText(QString::number(test));
	
	
	ui.histoVerticalLayout->setAlignment(Qt::AlignTop);
	updateLayoutContent();

	QObject::connect(actions[0], SIGNAL(triggered()), this, SLOT(selectDe()));
	QObject::connect(actions[1], SIGNAL(triggered()), this, SLOT(selectDeHisto()));

	layoutSetVisible(false);
	selectedDe = &dd;
}

void HeritageEx1::updateLayoutContent()
{
	clearLayout(ui.histoVerticalLayout);

	QPushButton * historiqueBtn = new QPushButton("Historique");
	histoLayoutWidgets.push_back(historiqueBtn);
	QObject::connect(historiqueBtn, SIGNAL(clicked()), this, SLOT(updateLayoutContent()));


	int * tab = deHisto.getHisto();
	for (int i = 0; i < deHisto.getNbVal(); i++)
	{
		QLabel * valueLabel = new QLabel(QString::number(tab[i]));
		histoLayoutWidgets.push_back(valueLabel);
	}

	for (int i = 0; i < histoLayoutWidgets.size(); i++)
	{
		ui.histoVerticalLayout->addWidget(histoLayoutWidgets[i]);
	}
}

void HeritageEx1::clearLayout(QLayout *layout)
{
	QLayoutItem *item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			clearLayout(item->layout());
			delete item->layout();
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}

	histoLayoutWidgets.clear();
}

void HeritageEx1::layoutSetVisible(bool bVisible)
{
	for (int i = 0; i < histoLayoutWidgets.size(); i++)
	{
		histoLayoutWidgets[i]->setVisible(bVisible);
	}
}

void HeritageEx1::updateDeValueLabels()
{
	int score;
	score += (*selectedDe);

	int scoreTotal;
	scoreTotal < (*selectedDe);

	ui.scoreDeLabel->setText("Score : " + QString::number(score));
	ui.scoreTotalLabel->setText(" Score total : " + QString::number(scoreTotal));
}

void HeritageEx1::pushButtonClicked()
{
	(*selectedDe)++;
	updateDeValueLabels();

	if(dynamic_cast<DeHisto*>(selectedDe) != NULL)
		updateLayoutContent();
}

void HeritageEx1::selectDe()
{
	layoutSetVisible(false);
	selectedDe = &dd;
	updateDeValueLabels();
}

void HeritageEx1::selectDeHisto()
{
	layoutSetVisible(true);
	updateLayoutContent();
	selectedDe = &deHisto;
	updateDeValueLabels();
}
