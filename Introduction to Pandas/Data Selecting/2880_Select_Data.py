import pandas as pd
from typing import List

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students.loc[
        students["student_id"] == 101,
        ["name", "age"] 
    ]