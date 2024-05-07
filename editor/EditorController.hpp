#pragma once

#include "EditorModel.hpp"
#include <memory>
#include <string>

class EditorController {
    std::unique_ptr<EditorModel> model;
public:
    EditorController(std::unique_ptr<EditorModel> model_) :
                    model(std::move(model_)) {}
    
    void saveToFile(const std::string& fileName) {
        std::cout << "START SAVING TO FILE : " << fileName << std::endl;
        model->forEach([](auto& shape){
            std::cout << shape->serialize();
        });
        std::cout << "END SAVING TO FILE" << std::endl;
    }
    void importFromFile(const std::string& fileName) {
        std::cout << "START IMPORTING DATA FROM FILE : " << fileName << std::endl;
        std::cout << "reading data from file, deserialization and model initialization\n";
        std::cout << "END IMPORTING DATA FROM FILE" << std::endl;
    }

    template <typename T, typename ... Args>
    std::shared_ptr<IShape> addShape(Args&&... args) {
        std::shared_ptr<IShape> shapePtr = std::make_shared<T>(args ...);
        model->addShape(shapePtr);
        return shapePtr;
    }

    void eraseShape(std::shared_ptr<IShape>& shape) {
        model->eraseShape(shape);
    }
};