#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "blockscene.h"

class DiagramScene;

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    //void buttonGroupClicked(int id);
    //void deleteItem();
    //void pointerGroupClicked(int id);
//    void bringToFront();
//    void sendToBack();
    //void itemInserted(BlockItem *item);
    //void sceneScaleChanged(const QString &scale);

//    void itemColorChanged();
//    void lineColorChanged();

//    void lineButtonTriggered();
    //void itemSelected(QGraphicsItem *item);
//    void about();

private:
    //void createToolBox();
    //void createActions();
    //void createMenus();
    //void createToolbars();
//    QWidget *createBackgroundCellWidget(const QString &text,
//                                        const QString &image);

    //QWidget *createCellWidget(const QString &text,
    //                          BlockItem::BlockType type);

    DiagramScene *scene;
    QGraphicsView *view;

    QAction *exitAction;
    QAction *addAction;
    QAction *deleteAction;

//    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *itemMenu;
//    QMenu *aboutMenu;

    QToolBar *editToolBar;
    QToolBar *pointerToolbar;

    QComboBox *sceneScaleCombo;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *pointerTypeGroup;

};

#endif // MAINWINDOW_H
