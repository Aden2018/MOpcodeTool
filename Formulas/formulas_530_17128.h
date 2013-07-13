#ifndef FORMULAS_530_17128_H
#define FORMULAS_530_17128_H

#include "formulasbase.h"
#include "QString"

class Formulas_530_17128 : public FormulasBase
{
public:

    Formulas_530_17128(quint16 opcode) : FormulasBase(opcode) { }

    QString Version()
    {
        return "5.3.0 17128";
    }

    QString GetAuthOffset()
    {
        // not found yet
        return "0";
    }

    QString GetCryptOffset()
    {
        if ((m_opcode & 0xA2) != 128)
        {
            quint32 offset = (m_opcode & 3 | ((m_opcode & 0x18 | ((m_opcode & 0x1C0 | (m_opcode >> 1) & 0x7E00) >> 1)) >> 1));

            if ((offset & 0x224) == 36)
                return QString::number(offset, 16);
        }

        return "0";
    }

    QString GetJAMOffset()
    {
        if ((m_opcode & 0xA2) == 128)
        {
            quint32 offset = m_opcode & 1 | ((m_opcode & 0x1C | ((m_opcode & 0x40 | ((unsigned int)m_opcode >> 1) & 0x7F80) >> 1)) >> 1);
            if (offset <= 0x2BA)
                return QString::number(offset, 16);
        }

        return "0";
    }

    QString GetUnk1Offset()
    {
        if ((m_opcode & 0xA2) != 128 && (m_opcode & 0x192A) == 2058)
            return QString::number(m_opcode & 1 | ((m_opcode & 4 | ((m_opcode & 0x10 | (((unsigned __int8)(m_opcode & 0xC0) | ((m_opcode & 0x600 | ((unsigned int)m_opcode >> 2) & 0x3800) >> 1)) >> 1)) >> 1)) >> 1), 16);

        return "0";
    }

    QString GetUnk2Offset()
    {
        if ((m_opcode & 0xA2) != 128 && (m_opcode & 0xA2) != 0
                && (m_opcode & 0x2A4) == 676
        )
            return QString::number(m_opcode & 3 | ((m_opcode & 0x18 | ((m_opcode & 0x40 | ((m_opcode & 0x100 | ((unsigned int)m_opcode >> 1) & 0x7E00) >> 1)) >> 1)) >> 1), 16);

        return "0";
    }

    QString GetUnk3Offset()
    {
        if ((m_opcode & 0xA2) != 128 && (m_opcode & 0xA2) != 0
                && (m_opcode & 0x2A4) == 548
        )
            return QString::number(m_opcode & 3 | ((m_opcode & 0x18 | ((m_opcode & 0x40 | ((m_opcode & 0x100 | ((unsigned int)m_opcode >> 1) & 0x7E00) >> 1)) >> 1)) >> 1), 16);

        return "0";
    }

    QString GetUnk4Offset()
    {
        if ((m_opcode & 0xA2) != 128 && (m_opcode & 0xA2) == 0)
            return QString::number(m_opcode & 1 | ((m_opcode & 0x1C | ((m_opcode & 0x40 | ((unsigned int)m_opcode >> 1) & 0x7F80) >> 1)) >> 1), 16);

        return "0";
    }
};

#endif // FORMULAS_530_17128_H
