#include "validacoes.h"

bool validaEmail(QString email) {

    bool retorno = true;
    QRegularExpression regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    if (!regex.match(email).hasMatch()) {
        retorno = false;
    }
    return retorno;
}

validacoes::validacoes()
{

}
