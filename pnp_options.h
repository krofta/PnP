#ifndef PNP_OPTIONS_H
#define PNP_OPTIONS_H

#include <QWidget>

namespace Ui {
class pnp_options;
}

class pnp_options : public QWidget
{
    Q_OBJECT

public:
    explicit pnp_options(QWidget *parent = nullptr);
    ~pnp_options();

private:
    Ui::pnp_options *ui;
};

#endif // PNP_OPTIONS_H
