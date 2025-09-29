//================================
// QT Features
#include <QMainWindow>    // Methods used => setWindowTitle(), setMinimumSize(), resize(), setCentralWidget()
#include <QVBoxLayout>    // Methods used => addWidget(), addLayout()
#include <QHBoxLayout>    // Methods used => addWidget(), addStretch()
#include <QPushButton>    // Methods used => setStyleSheet(), clicked signal, setText()
#include <QLabel>         // Methods used => setFont(), setText()
#include <QLineEdit>      // Methods used => setReadOnly(), setText(), clear(), setPlaceholderText(), setMaxLength()
#include <QTextEdit>      // Methods used => setReadOnly(), setFont(), setPlainText()
#include <QTabWidget>     // Methods used => addTab()
#include <QGroupBox>      // Methods used => addRow() via QFormLayout
#include <QMessageBox>    // Methods used => warning(), information()
#include <QFormLayout>    // Methods used => addRow()
#include <QSpinBox>       // Methods used => setRange(), setValue()
#include <QDoubleSpinBox> // Methods used => setRange(), setDecimals(), setValue(), setPrefix()
#include <QTableWidget>   // Methods used => setRowCount(), setItem(), setHorizontalHeaderLabels(), setSelectionBehavior(), setAlternatingRowColors()
#include <QHeaderView>    // Methods used => setStretchLastSection()
#include <QSplitter>      // Methods used => setSizes(), addWidget()
#include <QCloseEvent>    // Methods used => QCloseEvent *event
//================================
// Standard C++ Features
#include <memory>  // Methods used => std::shared_ptr, std::make_shared
#include <vector>  // Methods used => std::vector, size(), push_back()
#include <fstream> // Methods used => std::ofstream
//================================
// Class Declarations
#include "Payment.hpp"      // Methods used => getPaymentID(), getAmount(), getPaymentType()
#include "CardMethod.hpp"   // Methods used => constructor CardMethod<double>(paymentID, amount, cardNumber, holder, expiry, cvv)
#include "ChequeMethod.hpp" // Methods used => constructor ChequeMethod<double>(paymentID, amount, chequeNumber, bankName, accountHolder)
#include "Invoice.hpp"      // Methods used => getInvoiceID(), getCustomerName(), getTotalAmount(), getListOfPayments(), addPayment()