#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HeritageEx1.h"

class HeritageEx1 : public QMainWindow
{
    Q_OBJECT

public:
    HeritageEx1(QWidget *parent = Q_NULLPTR);

public slots:
	void pushButtonClicked();

private:
    Ui::HeritageEx1Class ui;
	int scoreTotal;
};
