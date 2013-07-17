#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formulasbase.h"
#include "QDebug"

// 1. Include your formulas here
#include "Formulas/formulas_530_17128.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 2. Then add your formulas version here
    ui->list->addItem("5.3.0 17128");

    connect(ui->input, SIGNAL(textChanged(QString)), this, SLOT(CalculOffset(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CalculOffset(QString input)
{
    FormulasBase *formulas = NULL;
    quint16 opcode = input.toShort(0, input.contains("x") ? 16 : 10);
    QString version = ui->list->currentText();

    ui->dec->setText(QString::number(opcode));

    // 3. Finally add your formulas handler here
    if (version == "5.3.0 17128")
        formulas = new Formulas_530_17128(opcode);

    if (formulas && formulas->Version() == version)
    {
        ui->auth->setText("0x" + formulas->GetAuthOffset());
        ui->jam->setText("0x" + formulas->GetJAMOffset());
        ui->crypt->setText("0x" + formulas->GetCryptOffset());
        ui->guild->setText("0x" + formulas->GetGuildOffset());
        ui->quest->setText("0x" + formulas->GetQuestOffset());
        ui->spell->setText("0x" + formulas->GetSpellOffset());
        ui->movement->setText("0x" + formulas->GetMovementOffset());
    }
}
