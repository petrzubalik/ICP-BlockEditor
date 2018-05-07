#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>
#include <QPoint>
#include <QPointF>

#include "blockitem.h"
#include "port.h"
#include "baseblock.h"
#include "operations.h"


MainWindow::MainWindow()
{
    createActions();
    createToolBox();
    createMenus();

    scene = new BlockScene(this, itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    connect(scene, SIGNAL(itemInserted(BlockItem*)),
            this, SLOT(itemInserted(BlockItem*)));
    connect(scene, SIGNAL(itemInserted(InputBlock*)),
            this, SLOT(itemInserted(InputBlock*)));
    connect(scene, SIGNAL(itemInserted(OutputBlock*)),
            this, SLOT(itemInserted(OutputBlock*)));

    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);

    scheme_name = "new scheme";
    setWindowTitle(scheme_name);
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

void MainWindow::itemInserted(InputBlock *item)
{
    pointerTypeGroup->button(int(BlockScene::MoveBlock))->setChecked(true);
    scene->setMode(BlockScene::Mode(pointerTypeGroup->checkedId()));
    buttonGroup->button(int(item->blockType()))->setChecked(false);
}

void MainWindow::itemInserted(OutputBlock *item)
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
    deleteAction->setStatusTip(tr("Delete block from scheme"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));

    // remove this ?????????
    exitAction = new QAction(tr("Exit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit BlockEditor application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    saveAction = new QAction(tr("Save"), this);
    saveAction->setStatusTip(tr("Save current scheme"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    save_as_Action = new QAction(tr("Save as"), this);
    save_as_Action->setStatusTip(tr("Save current scheme"));
    connect(save_as_Action, SIGNAL(triggered()), this, SLOT(save_as()));

    loadAction = new QAction(tr("Open"), this);
    loadAction->setStatusTip(tr("Open an existing scheme"));
    connect(loadAction, SIGNAL(triggered()), this, SLOT(loadScheme()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);
    fileMenu->addAction(save_as_Action);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(loadAction);

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
    for (BlockItem *block : operation_blocks)
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
    for (InputBlock *input : input_blocks)
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
    for (InputBlock *input : input_blocks)
    {
        input->propagate();
    }

    // 4. compute all operation blocks
    unsigned int counter = 0;
    for (unsigned int i = 0; i < operation_blocks.size(); i++)
    {
        for (BlockItem *block : operation_blocks)
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
    for (BlockItem *block : operation_blocks)
    {
        block->propagated = false;
    }
}


void MainWindow::debug(int)
{
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
    for (InputBlock *input : input_blocks)
    {
        input->propagate();
    }

}

void MainWindow::step(int)
{
    QMessageBox msgBox;

    for (BlockItem *block : operation_blocks)
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
    stepGroup->button(14)->setEnabled(false);
    stopGroup->button(15)->setEnabled(false);

    connect(buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));
    for (BlockItem *block : operation_blocks)
    {
        block->debug = false;
        block->propagated = false;
    }
    scene->update();

}


void MainWindow::save()
{
    QString file_name = scheme_name;

    if (file_name == "new scheme")
    {
        save_as();
    }
    saveScheme(file_name);
}


void MainWindow::save_as()
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
    saveScheme(file_name);
}


void MainWindow::saveScheme(QString file_name)
{

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

    out.setVersion(QDataStream::Qt_5_5);

    // write the data

    // 1) write input blocks
    out << (quint32)input_blocks.size();

    for (InputBlock *block : input_blocks)
    {
        out << block;
    }

    // 2) write operation blocks
    out << (quint32)operation_blocks.size();

    for (BlockItem *block : operation_blocks)
    {
        out << block;
    }

    // 2) write output blocks
    out << (quint32)output_blocks.size();

    for (OutputBlock *block : output_blocks)
    {
        out << block;
    }

    scheme_name = file_name;
    setWindowTitle(scheme_name);
}





void MainWindow::loadScheme()
{
    QString file_name = QFileDialog::getOpenFileName(this,
            tr("Open scheme"), "",
            tr("Block schemes (*.blk);;All Files (*)"));
    if (file_name.isEmpty())
        return;

    QFileInfo fi(file_name);
    if (fi.suffix() != "blk")
    {
        QMessageBox::warning(this, "title", "Unable to open file");
        return;
    }

    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_5);

    // Clear the scene
    input_blocks.clear();
    operation_blocks.clear();
    output_blocks.clear();
    scene->clear();


    // 1) load input blocks
    quint32 magic;
    unsigned int blocks_count;
    in >> magic;

    if (magic != 0x15786ABC)
    {
        QMessageBox::warning(this, "title", "Unable to open file");
        return;
    }
    in >> blocks_count;

    for (unsigned int i = 0; i < blocks_count; i++)
    {
        QPointF position;
        unsigned int connections_count;

        InputBlock *block = new InputBlock(itemMenu);
        scene->addItem(block);
        input_blocks.push_back(block);
        in >> position;
        block->setPos(position);

        in >> connections_count;
        for (unsigned int j = 0; j < connections_count; j++)
        {
            QPointF parent_pos;
            in >> parent_pos;
            block->connected_blocks.push_back(parent_pos);
        }
    }

    // 2) load operation blocks
    in >> blocks_count;

    for (unsigned int i = 0; i < blocks_count; i++)
    {
        QPointF position;
        unsigned int type; // unsigned ???
        unsigned int connections_count;
        BlockItem *block;

        in >> position;
        in >> type;

        switch (type) {
        case BaseBlock::Addition:
            block = new Addition(itemMenu);
            break;
        case BaseBlock::Subtraction:
            block = new Subtraction(itemMenu);
            break;
        case BaseBlock::Multiplication:
            block = new Multiplication(itemMenu);
            break;
        case BaseBlock::Division:
            block = new Division(itemMenu);
            break;
        }
        block->setPos(position);
        scene->addItem(block);
        operation_blocks.push_back(block);

        in >> connections_count;
        for (unsigned int j = 0; j < connections_count; j++)
        {
            QPointF parent_pos;
            in >> parent_pos;
            block->connected_blocks.push_back(parent_pos);
        }
    }

    // 3) load output blocks
    in >> blocks_count;

    for (unsigned int i = 0; i < blocks_count; i++)
    {
        QPointF position;
        OutputBlock *block = new OutputBlock(itemMenu);

        in >> position;
        block->setPos(position);
        output_blocks.push_back(block);
        scene->addItem(block);
    }

    // do all connections
    for (InputBlock *block : input_blocks)
    {
        for (QPointF position : block->connected_blocks)
        {
            QGraphicsItem *p = scene->itemAt(position, view->transform());
            BaseBlock *parent = qgraphicsitem_cast<BaseBlock *>(p);
            Connection *connection;

            if (parent->blockType() == BaseBlock::OutputBlock)
            {
                OutputBlock *out = qgraphicsitem_cast<OutputBlock *>(parent);
                connection = block->out_port->connect(out->in_port);
            }
            else
            {
                BlockItem *blk = qgraphicsitem_cast<BlockItem *>(parent);
                for (InputPort *port : blk->in_ports)
                {
                    if (!port->used)
                    {

                        connection = block->out_port->connect(port);
                        break;
                    }
                }
            }
            connection->setZValue(-1000);
            scene->addItem(connection);
            connection->updatePosition();
        }
    }

    for (BlockItem *block : operation_blocks)
    {
        for (QPointF position : block->connected_blocks)
        {
            QGraphicsItem *p = scene->itemAt(position, view->transform());
            BaseBlock *parent = qgraphicsitem_cast<BaseBlock *>(p);
            Connection *connection;

            if (parent->blockType() == BaseBlock::OutputBlock)
            {
                OutputBlock *out = qgraphicsitem_cast<OutputBlock *>(parent);

                connection = block->out_port->connect(out->in_port);
            }
            else
            {
                BlockItem *blk = qgraphicsitem_cast<BlockItem *>(parent);
                for (InputPort *port : blk->in_ports)
                {
                    if (!port->used)
                    {
                        connection = block->out_port->connect(port);
                        break;
                    }
                }
            }
            connection->setZValue(-1000);
            scene->addItem(connection);
            connection->updatePosition();

        }
    }

    scheme_name = file_name;
    setWindowTitle(scheme_name);
}

