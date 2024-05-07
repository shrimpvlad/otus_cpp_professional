#include "IShape.hpp"
#include "EditorModel.hpp"
#include "EditorView.hpp"
#include "EditorController.hpp"
#include <memory>

int main() {
    auto view = std::make_unique<EditorView>();
    auto model = std::make_unique<EditorModel>(std::move(view));
    auto controller = EditorController(std::move(model));

    auto square = controller.addShape<Square>(5, 10, 2, 2);
    auto circle = controller.addShape<Circle>(5, 4, 4);
    auto line1 = controller.addShape<Line>(13, 8, 2);
    auto line2 = controller.addShape<Line>(1, -2, 2);

    controller.saveToFile("output.txt");

    controller.eraseShape(line2);
}