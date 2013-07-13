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
    virtual QString GetUnk1Offset() = 0;
    virtual QString GetUnk2Offset() = 0;
    virtual QString GetUnk3Offset() = 0;
    virtual QString GetUnk4Offset() = 0;

protected:
    qint16 m_opcode;
};

#endif // FORMULASBASE_H
