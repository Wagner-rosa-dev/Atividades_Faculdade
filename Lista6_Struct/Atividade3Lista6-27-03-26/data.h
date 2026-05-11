#ifndef DATA_H
#define DATA_H

#include <compare>

class DATA
{
public:

    enum{ ANO_MIN = 2000, ANO_MAX = 2050 };
    enum{ FEVEREIRO = 2, JULHO = 7 };


    DATA() = default;

    DATA(short dia, short mes, short ano){
        change(dia, mes, ano);
    };

    ~DATA() = default;

    void change(short dia, short mes, short ano);

    void validate(){
        m_valid = ((m_dia >= 1 && m_dia <= lastDayOfMonth()) &&
                   (m_mes >= 1 && m_mes <= 12) &&
                   (m_ano >= ANO_MIN && m_ano <= ANO_MAX));

    }

    short lastDayOfMonth() const;

    bool isLeapYear() const;

    auto operator<=>(const DATA &other) const {
        if(const auto cmp = m_ano <=> other.m_ano; cmp != 0) return cmp;
        if(const auto cmp = m_mes <=> other.m_mes; cmp != 0) return cmp;
        return m_dia <=> other.m_dia;
    }

    bool operator==(const DATA &other) const {
        return(*this <=> other) == 0;
    }


    bool m_valid = false;
    short m_dia {0};
    short m_mes {0};
    short m_ano {0};


};

#endif // DATA_H
