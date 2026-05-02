import pandas as pd
from typing import List

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["bonus"] = employees["salary"] * 2
    return employees