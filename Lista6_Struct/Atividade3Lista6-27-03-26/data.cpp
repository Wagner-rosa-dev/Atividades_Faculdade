#include "data.h"

void DATA::change(short dia, short mes, short ano){
    m_dia = dia;
    m_mes = mes;
    m_ano = ano;

    validate();
}

short DATA::lastDayOfMonth() const{
    return m_mes != FEVEREIRO ? (30 + ((m_mes & 1) ^ (m_mes > JULHO))) :
                                (28 + isLeapYear());
}

bool DATA::isLeapYear() const{
    int res3 = m_ano % 400;
    int res1 = m_ano & 3;
    int res2 = m_ano % 100;

    if(res3 == 0 || (res1 == 0 && res2!= 0))
        return true;

    return false;
}
