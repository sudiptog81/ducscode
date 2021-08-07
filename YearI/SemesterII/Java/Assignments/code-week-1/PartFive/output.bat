for /l %%x in (1, 1, 100) do (
   java Main %%x >> output.txt
)