import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    red_company_id = company.loc[
        company["name"] == "RED",
        "com_id"
    ]

    red_sales_id = orders.loc[
        orders["com_id"].isin(red_company_id),
        "sales_id"
    ]

    return sales_person.loc[
        ~sales_person["sales_id"].isin(red_sales_id),
        ["name"]
    ]