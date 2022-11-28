#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;


namespace winrt::Test_SplitView::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}

void winrt::Test_SplitView::implementation::MainWindow::togglePaneButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

    if (splitView().IsPaneOpen()) {
        splitView().DisplayMode(SplitViewDisplayMode::Overlay);
        splitView().IsPaneOpen(NULL);  //판넬 안보임
    }
    else {
        splitView().IsPaneOpen("True"); // 판넬 보임
        splitView().DisplayMode(SplitViewDisplayMode::Inline);
    }
}

void winrt::Test_SplitView::implementation::MainWindow::ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (toggleSwitchLeftRight().IsOn()) {
        splitView().PanePlacement(SplitViewPanePlacement::Right);
    }
    else {
        splitView().PanePlacement(SplitViewPanePlacement::Left);
    }
}

void winrt::Test_SplitView::implementation::MainWindow::displayModeCombobox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    
    if (combo_inline().IsSelected()) {
        splitView().DisplayMode(SplitViewDisplayMode::Inline);
    }
    else if (combo_compactinline().IsSelected()) {
        splitView().DisplayMode(SplitViewDisplayMode::CompactInline); 
    }
    else if (combo_overlay().IsSelected()) {
        splitView().DisplayMode(SplitViewDisplayMode::Overlay);
    }
    else if (combo_compactoverlay().IsSelected()) {
        splitView().DisplayMode(SplitViewDisplayMode::CompactOverlay);
    }
}

void winrt::Test_SplitView::implementation::MainWindow::paneBackgroundCombobox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    // https://learn.microsoft.com/en-us/windows/apps/design/style/brushes
    if (combo_pink().IsSelected()) {
        SolidColorBrush PaneColor{ Colors::LightPink() };
        splitView().PaneBackground(PaneColor);
    }
    else if (combo_blue().IsSelected()) {
        SolidColorBrush PaneColor{ Colors::LightBlue() };
        splitView().PaneBackground(PaneColor);
    }
    else if (combo_green().IsSelected()) {
        SolidColorBrush PaneColor{ Colors::LightGreen() };
        splitView().PaneBackground(PaneColor);
    }
}

void winrt::Test_SplitView::implementation::MainWindow::openPaneLengthSlider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e)
{
    splitView().OpenPaneLength(e.NewValue());
}

void winrt::Test_SplitView::implementation::MainWindow::compactPaneLengthSlider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e)
{
    splitView().CompactPaneLength(e.NewValue());
}


void winrt::Test_SplitView::implementation::MainWindow::left_list_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    switch (left_list().SelectedIndex())
    {
    case 0:
        content().Text(L"Setting");
        break;
    case 1:
        content().Text(L"People");
        break;
    case 2:
        content().Text(L"Globe");
        break;
    case 3:
        content().Text(L"Message");
        break;
    case 4:
        content().Text(L"Mail");
        break;
    default:
        break;
    }
}
