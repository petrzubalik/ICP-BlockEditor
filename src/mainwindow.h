/**
  * @file mainwindow.h
  * @author Jan Koci (xkocij01), Petr Zubalik (xzubal04)
  * @date May 2018
  * @brief  Class for the main window of GUI
  *
  */

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

/**
 * @brief Class containing graphics and GUI methods for BlockEditor
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of MainWindow instance
     */
    MainWindow();

    /**
      * @brief Destructor of MainWindow instance
      */
    ~MainWindow();

    /**
     * @brief vector of all operation blocks in the scheme
     */
    std::vector<BlockItem*> operation_blocks;

    /**
     * @brief vector of all input blocks in the scheme
     */
    std::vector<InputBlock*> input_blocks;

    /**
     * @brief vector of all output blocks in the scheme
     */
    std::vector<OutputBlock*> output_blocks;

    

private slots:
    /**
     * @brief method that handles clicking on the buttons
     * @param id    id of the button in it's group
     */
    void buttonGroupClicked(int id);

    /**
     * @brief deleteItem
     */
    void deleteItem(); 

    /**
     * @brief method that handles switchin between line painting and pointing mode
     * @param id    id of the button in it's group
     */
    void pointerGroupClicked(int id);

    /**
     * @brief method that handles whole process of computing the scheme
     */
    void compute(int);

    /**
     * @brief method that handles stepping of the scheme
     */
    void debug(int);

    /**
     * @brief provides on step in the scheme
     */
    void step(int);

    /**
     * @brief stops the stepping mode
     */
    void stop(int);

    /**
     * @brief handles emiting of the signal itemInserted
     * @param item  block of type BlockItem
     */
    void itemInserted(BlockItem *item);
    /**
     * @brief handles emiting of the signal itemInserted
     * @param item  block of type InputBlock
     */
    void itemInserted(InputBlock *item);
    /**
     * @brief handles emiting of the signal itemInserted
     * @param item  block of type OutputBlock
     */
    void itemInserted(OutputBlock *item);
    /**
     * @brief handles scaling of the view
     * @param scale     how the view should be scaled
     */
    void sceneScaleChanged(const QString &scale);
    
    void saveScheme(QString file_name);
    void save();
    void save_as();
    void loadScheme();

private:


    QString scheme_name;


    /**
     * @brief creates a toolbox on the right side of the window
     */
    void createToolBox();

    /**
     * @brief creates actions of our program
     */
    void createActions();

    /**
     * @brief creates menus in the toolbar
     */
    void createMenus();

    /**
     * @brief creates toolbars on the top of the window
     */
    void createToolbars();

    /**
     * @brief sets "propagated" attribut of all blocks to false
     */
    void clean_blocks();

    /**
     * @brief finds out if all ports are used
     * @return true if all ports are used, else false
     */
    bool allPortsUsed();

    

    /**
     * @brief all_input_values
     * @return true if all input blocks have values, else false
     */
    bool all_input_values();


    /**
     * @brief          create a widget with icons of block types
     * @param text     name of operation
     * @param type     type of block type
     * @return         pointer to Qwidget
     */
    QWidget *createCellWidget(const QString &text,
                              BlockItem::BlockType type);

    /**
     * @brief   scene of the main window
     */
    BlockScene *scene;

    /**
     * @brief view of the main window
     */
    QGraphicsView *view;


    /**
     * @brief exits the running program
     */
    QAction *exitAction;

    /**
     * @brief saves created scheme
     */
    QAction *saveAction;

    QAction *save_as_Action;

    QAction *loadAction;


    /**
     * @brief deletes one selected block from a scheme
     */
    QAction *deleteAction;

//    QAction *aboutAction;

    /**
     * @brief file menu contains exit, save and load actions
     */
    QMenu *fileMenu;

    /**
     * @brief item menu contains delete action
     */
    QMenu *itemMenu;
//    QMenu *aboutMenu;

    /**
     * @brief editToolBar
     */
    QToolBar *editToolBar;

    /**
     * @brief allows switching between connection creating mode and pointing mode
     */
    QToolBar *pointerToolbar;

    /**
     * @brief used for scaling the view
     */
    QComboBox *sceneScaleCombo;

    /**
     * @brief contains buttonGroup with block type labels
     */
    QToolBox *toolBox;
    /**
     * @brief contains labels with block item types in toolbox
     */
    QButtonGroup *buttonGroup;

    /**
     * @brief tempGroup
     */
    QButtonGroup *tempGroup;

    /**
     * @brief contains debug labels in editToolBar
     */
    QButtonGroup *debugGroup;

    /**
     * @brief contains step labels in editToolBar
     */
    QButtonGroup *stepGroup;

    /**
     * @brief contains stop labels in editToolBar
     */
    QButtonGroup *stopGroup;

    /**
     * @brief contains pointer and line labels in pointerToolBar
     */
    QButtonGroup *pointerTypeGroup;

};

#endif // MAINWINDOW_H
