#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#include <QAbstractItemModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>

class classUsuario {
public:
    int id;
    QString idade;
    QString nome;
    QString senha;
    QString telefone;
    QString email;
};

class classCliente {
public:
    int id;
    QString idade;
    QString nome;
    QString telefone;
    QString email;
    QString endereco;
    QString documento;
};

class classLivro {
public:
    QString id;
    QString titulo;
    QString autor;
    QString ano;
    QString editora;
    int quantTotal;
    int quantDisp;
};

class classEmprestimo {
public:
    QString tituloLivro;
    QString IDemp;
    QString dataEmp;
    QString dataLim;
};

extern int idUserAtual;
extern QSqlDatabase banco;

class variaveis
{
public:
    variaveis();

};

#endif // VARIAVEIS_H
