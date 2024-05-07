#pragma once

#include "EditorModel.hpp"
#include <list>
#include <memory>

class EditorView
{
    void ClearScreen() {
        std::cout << "CLEARING SCREEN BEFORE DRAWING/REDRAWING\n";
    }
public:
    void Draw(std::list<std::shared_ptr<IShape>>& shapePool) {
        ClearScreen();
        std :: cout << "STARTING DRAWING\n";
        for (const auto& shape : shapePool) {
            shape->getMetaData();
        }
        std :: cout << "END DRAWING\n";
    }
};