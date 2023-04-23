#ifndef ENVGENWIDGET_H
#define ENVGENWIDGET_H

#include <QWidget>
#include <memory>

#include "../../Inc/CFlashToolTypes.h"

namespace Ui
{
    class EnvGenWidget;
}

class EnvGenWidget : public QWidget
{
    Q_OBJECT

public:
    enum class EnvGenMode : char {
        ENV_UNKNOWN = -1,
        ENV_GEN = 0,
        ENV_READBACK
    };

    explicit EnvGenWidget(QWidget *parent = nullptr);
    ~EnvGenWidget();

    EnvGenWidget::EnvGenMode get_env_gen_mode() const;

private slots:
    void EnvGenWidget::on_radioButton_env_gen_clicked();
    void EnvGenWidget::on_radioButton_env_readback_clicked();

private:
    Ui::EnvGenWidget *ui;
    QString get_env_platform() const;
    QString get_env_version() const;
    QString get_env_chip() const;
    QString get_env_id() const;
    void setUIState();
    void createConnections();

};

#endif
