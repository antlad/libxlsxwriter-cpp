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

    xlsxwriter::workbook *workbook = new xlsxwriter::workbook("test_chart_bar55.xlsx");
    xlsxwriter::worksheet *worksheet = workbook->add_worksheet();
    xlsxwriter::chart     *chart     = workbook->add_chart( xlsxwriter::LXW_CHART_BAR);

    /* For testing, copy the randomly generated axis ids in the target file. */
    chart->axis_id_1 = 64264064;
    chart->axis_id_2 = 64447232;

    uint8_t data[5][3] = {
        {1, 2,  3},
        {2, 4,  6},
        {3, 6,  9},
        {4, 8,  12},
        {5, 10, 15}
    };

    int row, col;
    for (row = 0; row < 5; row++)
        for (col = 0; col < 3; col++)
            worksheet->write_number(row, col, data[row][col] , NULL);

    xlsxwriter::chart_series *series1 = chart->add_series("", "=Sheet1!$A$1:$A$5");
    xlsxwriter::chart_series *series2 = chart->add_series("", "=Sheet1!$B$1:$B$5");
    xlsxwriter::chart_series *series3 = chart->add_series("", "=Sheet1!$C$1:$C$5");

    /* Add cache data for testing. */
    chart_add_data_cache(series1->values.get(), data[0], 5, 3, 0);
    chart_add_data_cache(series2->values.get(), data[0], 5, 3, 1);
    chart_add_data_cache(series3->values.get(), data[0], 5, 3, 2);

    worksheet->insert_chart(CELL("E9"), chart);

    int result = workbook->close(); return result;
}
