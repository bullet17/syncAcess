#ifndef TELADEVOLUCAO_H
#define TELADEVOLUCAO_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QWidget>
#include <QRegularExpression>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include "variaveis.h"

namespace Ui {
class telaDevolucao;
}

class telaDevolucao : public QDialog
{
    Q_OBJECT

public:
    explicit telaDevolucao(QWidget *parent = nullptr);
    ~telaDevolucao();

private slots:
    void on_listar_bt_clicked();

    void on_pushButton_clicked();

    void on_devolverLivro_bt_clicked();


private:
    Ui::telaDevolucao *ui;
};

#endif // TELADEVOLUCAO_H
