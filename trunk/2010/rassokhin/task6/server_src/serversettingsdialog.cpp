#include "serversettingsdialog.h"

#include <QtGui/QIntValidator>
#include <QtGui/QVBoxLayout>
#include <QtGui/QGridLayout>

ServerSettingsDialog::ServerSettingsDialog (ServerSettingsPtr settings, QWidget *parent)
        :QDialog(parent), settings(settings) {
    createObjects();
    connectObjects();
    reloadSettings();
}

void ServerSettingsDialog::createObjects() {

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    QGridLayout * settingsLayout = new QGridLayout();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Save |
                                     QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);

    lPort = new QLabel(tr("Port"),this);
    lAddress = new QLabel(tr("Address"),this);

    leAddress = new QLineEdit(this);
    lePort = new QLineEdit(this);

    lePort->setValidator(new QIntValidator(1, 65535, this));

    mainLayout->addLayout(settingsLayout);
    mainLayout->addWidget(buttonBox);
    settingsLayout->addWidget(lAddress,0,0);
    settingsLayout->addWidget(lPort,1,0);
    settingsLayout->addWidget(leAddress,0,1);
    settingsLayout->addWidget(lePort,1,1);
}

void ServerSettingsDialog::connectObjects() {
    connect(buttonBox, SIGNAL(accepted()), SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), SLOT(reject()));
}

void ServerSettingsDialog::accept() {
    qDebug("ServerSettingsDialog::accept()");
    settings->setAddress(leAddress->text());
    quint16 port = lePort->text().toInt();
    settings->setPort(port);
    this->close();
}

void ServerSettingsDialog::cancel() {
    this->close();
}

void ServerSettingsDialog::reloadSettings() {
    qDebug("ServerSettingsDialog::reloadSettings()");
    leAddress->setText(settings->getAddress());
    lePort->setText(QString::number(settings->getPort()));
}
