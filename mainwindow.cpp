#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>

#include "blockitem.h"


MainWindow::MainWindow()
{
    createActions();
    createToolBox();
    createMenus();

    scene = new BlockScene(this, itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(itemInserted(BaseBlock*)),
            this, SLOT(itemInserted(BaseBlock*)));

    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("BlockEditor - new scheme"));
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
    ;
}

void MainWindow::itemInserted(BaseBlock *item)
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
    layout->addWidget(createCellWidget(tr("Subtraction"), BaseBlock::Subtraction),0, 1);
    layout->addWidget(createCellWidget(tr("Multiplication"), BaseBlock::Multiplication), 1, 0);
    layout->addWidget(createCellWidget(tr("Division"), BaseBlock::Division), 1, 1);
    layout->addWidget(createCellWidget(tr("Input"), BaseBlock::InputBlock), 2, 0);
    layout->addWidget(createCellWidget(tr("Output"), BaseBlock::OutputBlock), 2, 1);


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
    deleteAction = new QAction(QIcon(":delete.png"), tr("Delete"), this);
    deleteAction->setShortcut(tr("Delete"));
    deleteAction->setStatusTip(tr("Delete block from scheme"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));

    // remove this ?????????
    exitAction = new QAction(tr("Exit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit BlockEditor application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    saveAction = new QAction(QIcon(":save.png"), tr("Save"), this);
    saveAction->setShortcut(tr("Save"));
    saveAction->setStatusTip(tr("Save current scheme"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveScheme()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);
    fileMenu->addAction(saveAction);

    itemMenu = menuBar()->addMenu(tr("&Item"));
    itemMenu->addAction(deleteAction);

}


void MainWindow::createToolbars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(deleteAction);

    QToolButton *playButton = new QToolButton;
    playButton->setIcon(QIcon(":play.png"));
    editToolBar->addWidget(playButton);

    tempGroup = new QButtonGroup(this);
    tempGroup->addButton(playButton, 12);
    connect(tempGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(compute(int)));

    QToolButton *debugButton = new QToolButton;
    debugButton->setIcon(QIcon(":debug.png"));
    editToolBar->addWidget(debugButton);

    debugGroup = new QButtonGroup(this);
    debugGroup->addButton(debugButton, 13);
    connect(debugGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(debug(int)));

    QToolButton *stepButton = new QToolButton;
    stepButton->setIcon(QIcon(":step.png"));
    stepButton->setEnabled(false);
    editToolBar->addWidget(stepButton);

    stepGroup = new QButtonGroup(this);
    stepGroup->addButton(stepButton, 14);
    connect(stepGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(step(int)));

    QToolButton *stopButton = new QToolButton;
    stopButton->setIcon(QIcon(":stop.png"));
    stopButton->setEnabled(false);
    editToolBar->addWidget(stopButton);

    stopGroup = new QButtonGroup(this);
    stopGroup->addButton(stopButton, 15);
    connect(stopGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(stop(int)));

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
            pixmap = new QPixmap(":add_block.jpg");
            break;
        case BaseBlock::InputBlock:
            pixmap = new QPixmap(":input.jpg");
            break;
        case BaseBlock::Subtraction:
            pixmap = new QPixmap(":sub_block.jpg");
            break;
        case BaseBlock::Division:
            pixmap = new QPixmap(":div_block.jpg");
            break;
        case BaseBlock::Multiplication:
            pixmap = new QPixmap(":mul_block.jpg");
            break;
        case BaseBlock::OutputBlock:
            pixmap = new QPixmap(":output.jpg");
            break;
        default:
            ;
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


void MainWindow::deleteItem()
{
    ;
}

bool MainWindow::allPortsUsed()
{
    QMessageBox msgBox;
    // check that all ports are used (connected)
    for (BaseBlock *block : operation_blocks)
    {
        if (!block->all_ports_used())
        {
            msgBox.setText("All ports must be connected");
            msgBox.exec();
            return false;
        }
    }
    return true;
}

bool MainWindow::all_input_values()
{
    QMessageBox msgBox;
    for (BaseBlock *input : input_blocks)
    {
        if (!input->has_value())
        {
            if (input->all_ports_used())
            {
                msgBox.setText("All input blocks must have values");
                msgBox.exec();
                return false;
            }
        }
    }
    return true;
}

void MainWindow::compute(int)
{
    QMessageBox msgBox;
    // 1. check that all ports are used (connected)
    if (!allPortsUsed())
    {
        return;
    }

    // 2. check that all input blocks have values
    if (!all_input_values())
    {
        return;
    }

    // 3. propagate input blocks
    for (BaseBlock *input : input_blocks)
    {
        input->propagate();
    }

    // 4. compute all operation blocks
    unsigned int counter = 0;
    for (unsigned int i = 0; i < operation_blocks.size(); i++)
    {
        for (BaseBlock *block : operation_blocks)
        {
            if (block->is_computable() && (!block->propagated))
            {
                try
                {
                    block->operation();
                    counter++;
                    break;
                }
                catch (std::logic_error)
                {
                    msgBox.setText("ERROR: division by zero");
                    msgBox.exec();
                    clean_blocks();
                    return;
                }

            }
        }
    }

    // check presence of connection loops
    if (counter < operation_blocks.size())
    {
        msgBox.setText("ERROR: scheme contains cycles");
        msgBox.exec();
        return;
    }

    // update the scene
    scene->update();

    // clean blocks
    clean_blocks();

    //

}

void MainWindow::clean_blocks()
{
    for (BaseBlock *block : operation_blocks)
    {
        block->propagated = false;
    }
}


void MainWindow::debug(int)
{
    std::cout << "Debug button clicked !" << std::endl;
    stepGroup->button(14)->setEnabled(true);
    stopGroup->button(15)->setEnabled(true);

    buttonGroup->disconnect(); // better use disable ???

    clean_blocks();
    if (!allPortsUsed())
    {
        stop(0);
        return;
    }

    if (!all_input_values())
    {
        stop(0);
        return;
    }

    // 3. propagate input blocks
    for (BaseBlock *input : input_blocks)
    {
        input->propagate();
    }

}

void MainWindow::step(int)
{
    QMessageBox msgBox;
    std::cout << "Step button clicked !" << std::endl;

    for (BaseBlock *block : operation_blocks)
    {
        if (block->is_computable() && (!block->propagated))
        {
            try
            {
                block->operation();
                block->debug = true;
                scene->update();
                return;
            }
            catch (std::logic_error)
            {
                msgBox.setText("ERROR: division by zero");
                msgBox.exec();
                clean_blocks();
                return;
            }

        }
    }
    stop(0);
}

void MainWindow::stop(int)
{
    std::cout << "Stop button clicked !" << std::endl;
    stepGroup->button(14)->setEnabled(false);
    stopGroup->button(15)->setEnabled(false);

    connect(buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    for (BaseBlock *block : operation_blocks)
    {
        block->debug = false;
        block->propagated = false;
    }
    scene->update();

}

void MainWindow::saveScheme()
{
    // 1. get filename
    QString file_name = QFileDialog::getSaveFileName(this,
            tr("Save block scheme"), "",
            tr("Block scheme (*.blk);;All Files (*)"));

    if (file_name.isEmpty())
        return;

    QFileInfo fi(file_name);
    if (fi.suffix() != "blk")
    {
        QMessageBox::warning(this, "title", "Unable to open file");
        return;
    }
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
                       file.errorString());
        return;
    }

    // 2. Magic number + QT versior
    QDataStream out(&file);

    out << (quint32)0x15786ABC;
    out << (quint32)1;

    out.setVersion(QDataStream::Qt_5_5);

    // write the data

    // 1) write number of blocks;
    out << (quint32)input_blocks.size();
    out << (quint32)operation_blocks.size();
    out << (quint32)output_blocks.size();

    // 2) write all blocks
    for (BaseBlock *block : input_blocks)
    {
        out << block;
    }
    for (BaseBlock *block : operation_blocks)
    {
        out << block;
    }
    for (BaseBlock *block : output_blocks)
    {
        out << block;
    }
}




