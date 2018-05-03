#include "blockscene.h"

BlockScene::BlockScene(QMenu *itemMenu, QObject *parent)
{
    myItemMenu = itemMenu;
    myMode = MoveBlock;
    myItemType = BaseBlock::InputBlock;
    line = 0;
}


void BlockScene::setMode(Mode mode)
{
    myMode = mode;
}


