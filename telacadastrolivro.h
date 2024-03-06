#ifndef TELACADASTROLIVRO_H
#define TELACADASTROLIVRO_H

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
#include "variaveis.h"

namespace Ui {
class telaCadastroLivro;
}

class telaCadastroLivro : public QDialog
{
    Q_OBJECT

public:
    explicit telaCadastroLivro(QWidget *parent = nullptr);
    ~telaCadastroLivro();

private slots:
    void on_pushButton_clicked();

    void on_codLivro_txt_editingFinished();

    void on_tituloLivro_txt_editingFinished();

    void on_autorLivro_txt_editingFinished();

    void on_anoLivro_txt_editingFinished();

    void on_editoraLivro_txt_editingFinished();

    void on_cadastrarLivro_btn_clicked();

    void on_quantLivro_txt_editingFinished();

private:
    Ui::telaCadastroLivro *ui;
};

#endif // TELACADASTROLIVRO_H
