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

    std::shared_ptr<xlsxwriter::workbook> workbook  = std::make_shared<xlsxwriter::workbook>("test_print_area05.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();

    worksheet->set_paper(9);
    worksheet->set_vertical_dpi(200);

    worksheet->print_area(RANGE("A1:A1048576"));

    worksheet->write_string(CELL("A1"), "Foo" , NULL);

    int result = workbook->close(); return result;
}
