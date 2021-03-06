/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2016, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.hpp"

int main() {

    std::shared_ptr<xlsxwriter::workbook> workbook  = std::make_shared<xlsxwriter::workbook>("test_escapes08.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();

    /* Test an already escaped string. */
    worksheet->write_url_opt(CELL("A1"), "http://example.com/%5b0%5d", NULL, "http://example.com/[0]");

    int result = workbook->close(); return result;
}
