#include "Libraries.hpp"

class PaymentSystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    PaymentSystemWindow(QWidget *parent = nullptr);
    ~PaymentSystemWindow();

private slots:
    //================================
    // Payment Operations
    void addCardPayment();
    void addChequePayment();
    void clearCardForm();
    void clearChequeForm();
    //================================
    // Invoice Operations
    void refreshInvoiceDisplay();
    void newInvoice();
    void showPaymentDetails();

private:
    //================================
    // Main Window Setup
    void setupUI();
    //================================
    // Card Payment Tab Setup
    void setupCardPaymentTab();
    //================================
    // Cheque Payment Tab Setup
    void setupChequePaymentTab();
    //================================
    // Invoice Tab Setup
    void setupInvoiceTab();
    //================================
    // Invoice Display Updates
    void updateInvoiceDisplay();
    void updatePaymentTable();
    //================================
    // UI Components
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    //================================
    // Card Payment Tab
    QWidget *cardTab;
    QLineEdit *cardPaymentIDEdit;
    QDoubleSpinBox *cardAmountSpinBox;
    QLineEdit *cardNumberEdit;
    QLineEdit *cardHolderEdit;
    QLineEdit *cardExpiryEdit;
    QSpinBox *cardCvvSpinBox;
    QPushButton *addCardButton;
    QPushButton *clearCardButton;
    //================================
    // Cheque Payment Tab
    QWidget *chequeTab;
    QLineEdit *chequePaymentIDEdit;
    QDoubleSpinBox *chequeAmountSpinBox;
    QSpinBox *chequeNumberSpinBox;
    QLineEdit *bankNameEdit;
    QLineEdit *accountHolderEdit;
    QPushButton *addChequeButton;
    QPushButton *clearChequeButton;
    //================================
    // Invoice Tab
    QWidget *invoiceTab;
    QLineEdit *invoiceIDEdit;
    QLineEdit *customerNameEdit;
    QPushButton *newInvoiceButton;
    QLabel *totalAmountLabel;
    QTableWidget *paymentsTable;
    QTextEdit *invoiceDisplayArea;
    QPushButton *refreshButton;
    //================================
    // temporary CSV storage
    QString simulatedServerFile = "simulated_server.csv";
    void saveInvoiceToCSV(); // save the current invoice to CSV
    void clearCSV();         // clear the CSV file
    void closeEvent(QCloseEvent *event);
    //================================
    // Data
    std::shared_ptr<Invoice> currentInvoice;
    int nextPaymentID;
};
