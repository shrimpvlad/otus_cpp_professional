#pragma once

#include "IShape.hpp"
#include "EditorView.hpp"
#include <list>
#include <memory>
#include <algorithm>

class EditorModel{
public:
    explicit EditorModel(std::unique_ptr<EditorView> view_) : view(std::move(view_)){}
    void addShape(std::shared_ptr<IShape>& shape) {
        std::cout << "adding new shape in model" << std::endl;
        shapePool.emplace_back(std::move(shape));    
    }
    void eraseShape([[maybe_unused]] std::shared_ptr<IShape>& shape)
    {
        std::cout << "erase shape from model" << std::endl;
        // if we try to delete shape which doesn`t exist -> throw exception
    }
    template<typename T>
    void forEach(T callBackFunc) {
        std::for_each(shapePool.begin(), shapePool.end(), callBackFunc);
    }

private:
    std::list<std::shared_ptr<IShape>> shapePool;
    std::unique_ptr<EditorView> view;
};