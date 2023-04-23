#include <QDebug>

#include "EnvGenWidget.h"
#include "ui_EnvGenWidget.h"
#include "../../Logger/Log.h"

EnvGenWidget::EnvGenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvGenWidget)
{
    ui->setupUi(this);

    setUIState();

    createConnections();
}

EnvGenWidget::~EnvGenWidget()
{
    delete ui;
}

// EnvGenWidget::

EnvGenWidget::EnvGenMode EnvGenWidget::get_env_gen_mode() const
{
    EnvGenWidget::EnvGenMode mode = EnvGenWidget::EnvGenMode::ENV_UNKNOWN;
    if (ui->radioButton_env_gen->isChecked())
        mode = EnvGenWidget::EnvGenMode::ENV_GEN;
    if (ui->radioButton_env_readback->isChecked())
        mode = EnvGenWidget::EnvGenMode::ENV_READBACK;

    return mode;
}

void EnvGenWidget::setUIState()
{
    if (get_env_gen_mode() == EnvGenWidget::EnvGenMode::ENV_GEN)
    {
        on_radioButton_env_gen_clicked();
    }
    else if (get_env_gen_mode() == EnvGenWidget::EnvGenMode::ENV_READBACK)
    {
        on_radioButton_env_readback_clicked();
    }
}

void EnvGenWidget::createConnections()
{
    connect(ui->radioButton_env_gen, &QRadioButton::clicked, this, &EnvGenWidget::on_radioButton_env_gen_clicked);
    connect(ui->radioButton_env_readback, &QRadioButton::clicked, this, &EnvGenWidget::on_radioButton_env_readback_clicked);
}

void EnvGenWidget::on_radioButton_env_gen_clicked()
{
    ui->groupBox_env_option->setVisible(true);
}

void EnvGenWidget::on_radioButton_env_readback_clicked()
{
    ui->groupBox_env_option->setVisible(false);
}

QString EnvGenWidget::get_env_platform() const
{
    return ui->comboBox_env_plat->currentText();
}

QString EnvGenWidget::get_env_version() const
{
    return ui->comboBox_env_ver->currentText();
}

QString EnvGenWidget::get_env_chip() const
{
    return ui->comboBox_env_chip->currentText();
}

QString EnvGenWidget::get_env_id() const
{
    return ui->lineEdit_env_id->text();
}
