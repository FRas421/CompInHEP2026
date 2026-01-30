import subprocess
from concurrent.futures import ThreadPoolExecutor
import os

EXEC = "./main"
N = 10
OUTDIR = "output_py"

os.makedirs(OUTDIR, exist_ok=True)

def run_job(i):
    with open(f"{OUTDIR}/out_{i}.txt", "w") as f:
        subprocess.run([EXEC, str(i)], stdout=f)

with ThreadPoolExecutor(max_workers=N) as executor:
    executor.map(run_job, range(1, N + 1))

print("All jobs finished.")
