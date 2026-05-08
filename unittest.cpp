#include "CppUnitTest.h"
#include "../task2/point.h"
#include "../task2/color.h"
#include "../task2/linestyle.h"
#include "../task2/line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(GeometryTests)
    {
    public:
        
        TEST_METHOD(Point_Constructor_InitializesCorrectly)
        {
            double expectedX = 10.5;
            double expectedY = 20.0;
            Point p(expectedX, expectedY);

            Assert::AreEqual(expectedX, p.x);
            Assert::AreEqual(expectedY, p.y);
        }

        TEST_METHOD(Point_EqualityOperator_Works)
        {
            Point p1(5.0, 5.0);
            Point p2(5.0, 5.0);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(Color_Constructor_ThrowsExceptionOnInvalidValue)
        {
            auto action = [] {Color c(300, 0, 0); };
            Assert::ExpectException<std::out_of_range>(action);
        }

        TEST_METHOD(LineStyle_Thickness_FixesNegativeValues)
        {
            LineStyle s(LineType::solid, -10);
            Assert::AreEqual(1, s.thickness); 
        }

        TEST_METHOD(Line_SetAppearance_UpdatesValues)
        {
            Line l(Point(0, 0), Point(10, 10));
            Color newColor(0, 0, 255);
            LineStyle newStyle(LineType::dash, 3);

            l.setAppearance(newStyle, newColor);
        }
    };
}
