/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef QmitkStoreSCPLauncher_h
#define QmitkStoreSCPLauncher_h

#include <QProcess>
#include <QString>
#include "QmitkStoreSCPLauncherBuilder.h"

class QmitkStoreSCPLauncher : public QObject
{
    Q_OBJECT

public:
    QmitkStoreSCPLauncher(QmitkStoreSCPLauncherBuilder* builder);
    virtual ~QmitkStoreSCPLauncher();

    public slots:
        void StartStoreSCP();
        void OnProcessError(QProcess::ProcessError error);
        void OnStateChanged(QProcess::ProcessState status);


private:
    void FindPathToStoreSCP();
    void SetArgumentList(QmitkStoreSCPLauncherBuilder* builder);
    QString ArgumentListToQString();
    QString m_PathToStoreSCP;

    QProcess* m_StoreSCP;
    QStringList m_ArgumentList;
};
#endif //QmitkStoreSCPLauncher_h