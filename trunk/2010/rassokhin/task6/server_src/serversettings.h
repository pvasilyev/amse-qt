#ifndef SERVERSETTINGS_H
#define SERVERSETTINGS_H

#include <QString>
#include <QSettings>

class ServerSettings {
public:
    ServerSettings(QString address = "127.0.0.1", quint16 port = 13000)
        : _address(address), _port(port) {};

    void saveSettings(QSettings * settings) const;
    void loadSettings(QSettings * settings);


    void setAddress(QString address) { _address = address; }
    void setPort(quint16 port) { _port = port; }
    QString getAddress() const { return _address; }
    quint16 getPort() const { return _port; }

private:
    QString _address;
    quint16 _port;
};

typedef ServerSettings* ServerSettingsPtr;
#endif // SERVERSETTINGS_H
