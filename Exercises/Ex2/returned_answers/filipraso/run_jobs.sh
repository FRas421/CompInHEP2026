EXEC=./main.exe
N=10

mkdir -p output

for i in $(seq 1 $N); do
    $EXEC $i > output/out_$i.txt &
done

wait
echo "All jobs finished."
