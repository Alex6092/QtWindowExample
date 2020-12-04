#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HeritageEx1.h"
#include "De.h"
#include "DeHisto.h"

class HeritageEx1 : public QMainWindow
{
    Q_OBJECT

public:
    HeritageEx1(QWidget *parent = Q_NULLPTR);

public slots:
	void pushButtonClicked();
	void selectDe();
	void selectDeHisto();
	void updateLayoutContent();

private:
    Ui::HeritageEx1Class ui;
	//int scoreTotal;

	QList<QWidget*> histoLayoutWidgets;
	void clearLayout(QLayout *);
	void layoutSetVisible(bool bVisible);
	void updateDeValueLabels();

	De * selectedDe;
	De dd;
	DeHisto deHisto;
};
