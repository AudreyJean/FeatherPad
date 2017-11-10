/*
 * Copyright (C) Pedram Pourang (aka Tsu Jan) 2014 <tsujan2000@gmail.com>
 *
 * FeatherPad is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FeatherPad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PREF_H
#define PREF_H

#include <QDialog>
#include <QStyledItemDelegate>
#include <QTableWidgetItem>
#include "config.h"

namespace FeatherPad {

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    Delegate (QObject *parent = 0);

    virtual QWidget* createEditor (QWidget *parent,
                                   const QStyleOptionViewItem&,
                                   const QModelIndex&) const;
    virtual bool eventFilter (QObject *object, QEvent *event);
};

namespace Ui {
class PrefDialog;
}

class PrefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrefDialog (const QHash<QString, QString> &defaultShortcuts, QWidget *parent = 0);
    ~PrefDialog();

private slots:
    void onClosing();
    void prefSize (int checked);
    void prefStartSize (int value);
    void prefIcon (int checked);
    void prefIconless (int checked);
    void prefToolbar (int checked);
    void prefMenubar (int checked);
    void prefSearchbar (int checked);
    void prefStatusbar (int checked);
    void prefFont (int checked);
    void prefWrap (int checked);
    void prefIndent (int checked);
    void prefAutoBracket (int checked);
    void prefLine (int checked);
    void prefSyntax (int checked);
    void prefWhiteSpace (int checked);
    void prefEndings (int checked);
    void prefDarkColScheme (int checked);
    void prefColValue (int value);
    void prefAppendEmptyLine (int checked);
    void prefScrollJumpWorkaround (int checked);
    void prefTabWrapAround (int checked);
    void prefHideSingleTab (int checked);
    void prefMaxSHSize (int value);
    void prefExecute (int checked);
    void prefCommand (QString command);
    void prefRecentFilesNumber (int value);
    void prefOpenRecentFile (int value);
    void prefNativeDialog (int checked);
    void prefSidePaneMode (int checked);
    void prefSplitterPos (int checked);
    void prefInertialScrolling (int checked);
    void showWhatsThis();
    void prefShortcuts();
    void defaultSortcuts();
    void onShortcutChange (QTableWidgetItem *item);

private:
    void closeEvent (QCloseEvent *event);
    void prefTabPosition();
    void prefRecentFilesKind();
    void showPrompt (QString str = QString(), bool temporary = false);

    Ui::PrefDialog *ui;
    QWidget * parent_;
    bool darkBg_, sysIcons_, iconless_, showWhiteSpace_, showEndings_;
    int darkColValue_, lightColValue_, recentNumber_;
    QHash<QString, QString> shortcuts_, newShortcuts_, defaultShortcuts_;
    QString prevtMsg_;
    QTimer *promptTimer_;
};

}

#endif // PREF_H
