#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

#include "blockitem.h"


MainWindow::MainWindow()
{
    createActions();
    createToolBox();
    createMenus();

    scene = new BlockScene(itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(itemInserted(BlockItem*)),
            this, SLOT(itemInserted(BlockItem*)));

    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("BlockEditor"));
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
    ;
}

void MainWindow::itemInserted(BlockItem *item)
{
    pointerTypeGroup->button(int(BlockScene::MoveBlock))->setChecked(true);
    scene->setMode(BlockScene::Mode(pointerTypeGroup->checkedId()));
    buttonGroup->button(int(item->blockType()))->setChecked(false);
}

void MainWindow::createToolBox()
{
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true); // false ??
    connect(buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createCellWidget(tr("Addition"), BaseBlock::Addition), 0, 0);
    layout->addWidget(createCellWidget(tr("Subtraction"), BaseBlock::Addition),0, 1);
    layout->addWidget(createCellWidget(tr("Multiplication"), BaseBlock::Addition), 1, 0);
    layout->addWidget(createCellWidget(tr("Division"), BaseBlock::Addition), 1, 1);
    layout->addWidget(createCellWidget(tr("Input"), BaseBlock::InputBlock), 2, 0);
    layout->addWidget(createCellWidget(tr("Output"), BaseBlock::Addition), 2, 1);


    layout->setRowStretch(3, 10);
    layout->setColumnStretch(2, 10);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(layout);

    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget, tr("Block items"));

}

void MainWindow::createActions()
{
    deleteAction = new QAction(QIcon(":delete.png"), tr("&Delete"), this);
    deleteAction->setShortcut(tr("Delete"));
    deleteAction->setStatusTip(tr("Delete item from editor"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit Scenediagram example"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    itemMenu = menuBar()->addMenu(tr("&Item"));
    itemMenu->addAction(deleteAction);
}


void MainWindow::createToolbars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(deleteAction);

    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon(":pointer.png"));
    QToolButton *linePointerButton = new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QIcon(":linepointer.png"));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(pointerButton, int(BlockScene::MoveBlock));
    pointerTypeGroup->addButton(linePointerButton, int(BlockScene::InsertLine));
    connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(pointerGroupClicked(int)));

    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(sceneScaleChanged(QString)));

    pointerToolbar = addToolBar(tr("Pointer type"));
    pointerToolbar->addWidget(pointerButton);
    pointerToolbar->addWidget(linePointerButton);
    pointerToolbar->addWidget(sceneScaleCombo);
}

QWidget *MainWindow::createCellWidget(const QString &text, BaseBlock::BlockType type)
{
    QPixmap *pixmap;
    switch (type)
    {
        case BaseBlock::Addition:
            pixmap = new QPixmap(":block_div.jpg");
            break;
        case BaseBlock::InputBlock:
            pixmap = new QPixmap(":input.jpg");
            break;
        default:
            pixmap = new QPixmap(":block_div.jpg");
            break;
    }

    QIcon icon(*pixmap);

    QToolButton *button = new QToolButton;
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    buttonGroup->addButton(button, int(type));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}

void MainWindow::buttonGroupClicked(int id)
{
    QList<QAbstractButton *> buttons = buttonGroup->buttons();
    foreach (QAbstractButton *button, buttons) {
        if (buttonGroup->button(id) != button)
            button->setChecked(false);
    }
    scene->setItemType(BaseBlock::BlockType(id));
    scene->setMode(BlockScene::InsertBlock);
}

void MainWindow::pointerGroupClicked(int)
{
    scene->setMode(BlockScene::Mode(pointerTypeGroup->checkedId()));
}

void MainWindow::sceneScaleChanged(const QString &scale)
{
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QMatrix oldMatrix = view->matrix();
    view->resetMatrix();
    view->translate(oldMatrix.dx(), oldMatrix.dy());
    view->scale(newScale, newScale);
}

