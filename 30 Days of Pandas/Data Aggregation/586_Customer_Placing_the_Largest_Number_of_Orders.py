import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    result = orders.groupby("customer_number", as_index=False)["order_number"].count()
    return result.loc[
        result["order_number"] == result["order_number"].max(),
        ["customer_number"]
    ]