#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "blockscene.h"
#include "blockitem.h"
#include "inputblock.h"
#include "outputblock.h"

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

    std::vector<BaseBlock*> operation_blocks;
    std::vector<BaseBlock*> input_blocks;
    std::vector<BaseBlock*> output_blocks;

private slots:
    void buttonGroupClicked(int id);
    void deleteItem();
    void pointerGroupClicked(int id);
    void compute(int);

    void itemInserted(BaseBlock *item);
    void sceneScaleChanged(const QString &scale);

private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();


    QWidget *createCellWidget(const QString &text,
                              BlockItem::BlockType type);

    BlockScene *scene;
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
    QButtonGroup *tempGroup;
    QButtonGroup *pointerTypeGroup;

};

#endif // MAINWINDOW_H
