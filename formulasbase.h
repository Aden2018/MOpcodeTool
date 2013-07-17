#ifndef FORMULASBASE_H
#define FORMULASBASE_H

#include "QString"

class FormulasBase
{
public:
    FormulasBase(quint16 opcode) : m_opcode(opcode) { }

    virtual QString Version() = 0;
    virtual QString GetAuthOffset() = 0;
    virtual QString GetCryptOffset() = 0;
    virtual QString GetJAMOffset() = 0;
    virtual QString GetGuildOffset() = 0;
    virtual QString GetQuestOffset() = 0;
    virtual QString GetSpellOffset() = 0;
    virtual QString GetMovementOffset() = 0;

protected:
    qint16 m_opcode;
};

#endif // FORMULASBASE_H
