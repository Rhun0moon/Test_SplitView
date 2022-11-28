#pragma once

#include "MainWindow.g.h"

using namespace winrt;
using namespace Microsoft::UI;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Controls::Primitives;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Input;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

namespace winrt::Test_SplitView::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void displayModeCombobox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
        void paneBackgroundCombobox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
        void togglePaneButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void openPaneLengthSlider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);
        void compactPaneLengthSlider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);
        void left_list_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
    };
}

namespace winrt::Test_SplitView::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
