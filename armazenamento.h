#ifndef ARMAZENAMENTO_H
#define ARMAZENAMENTO_H

#include <QAbstractItemModel>
#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <string>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QtSql>
#include <QSqlQueryModel>
#include "telamainmenu.h"
#include "variaveis.h"

class armazenamento
{
public:
};

QVector<classUsuario> criaListaUsuarios();
QVector<classLivro> criaListaLivros();
QVector<classCliente> criaListaClientes();
QVector<classEmprestimo> criaListaEmprestimosCliente(QString idCliente);
bool armazenaCliente(classCliente clienteCadastrado);
bool armazenaUsuario(classUsuario usuarioCadastrado);
bool armazenaLivro(classLivro livroCadastrado);
QString armazenaEmprestimo(QString idLivro, QString idCliente, QDate dataEmp);
void armazenaDevolucao(QString codEmp);
bool consultaSeDevolvido(QString idEmp);
QString consultaDataDevolucao(QString idEmp);
QString consultaDataLimite (QString idEmp);
int consultaQuantDisponivel(QString idLivro);
bool consultaEmprestimoDuplo(QString idCliente, QString idLivro);
bool consultaLivroAtrasadoCliente(QString idCliente);
QString consultaSenhaUsuario (QString idDigitado);
QString consultaNomeUsuario (int idUsuario);
QString consultaIdClientePeloNome(QString nomeCliente);
QString consultaIdLivroPeloTitulo(QString tituloLivro);
int criaIdCliente();
int criaIdUsuario();



#endif // ARMAZENAMENTO_H
