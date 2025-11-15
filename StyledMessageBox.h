#pragma once

// 3rd party includes
#include <QMessageBox>
#include <QString>

// Custom styled message box class
class StyledMessageBox : public QMessageBox {
    Q_OBJECT

  public:
    StyledMessageBox(const QString &title, const QString &text, const QString &buttonText,
                     QWidget *parent = nullptr);

  private:
    // Initializes the window
    void createWindow();

    // Shows window on top of other windows
    void makeWindowStayOnTop();

    // Waits with execution until button is pressed
    void waitForButtonPressed();

    // Plays the Microsoft alert sound
    void playAlertSound();

    // Adds a custom-styled button to the message box
    // 	    @param buttonText The button text of the message box
    void addCustomButton(const QString &buttonText);

    // Adds a title, icon and text content to the message box
    //      @param title The title of the message box
    // 	    @param text The main text content of the message box
    void addTextContent(const QString &title, const QString &text);

    // Applies custom CSS styles to the button
    void addCss();
};