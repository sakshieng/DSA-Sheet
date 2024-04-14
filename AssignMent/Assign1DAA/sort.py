import heapq
import os
def sort_large_file(input_file, output_file, chunk_size=100*1024*1024):
    # Step 1: Divide the large file into smaller sorted chunks
    def sort_chunk(chunk):
        return sorted(chunk)

    temp_files = []
    with open(input_file, 'r') as infile:
        while True:
            chunk = infile.read(chunk_size)
            if not chunk:
                break
            sorted_chunk = sort_chunk(chunk.split('\n'))
            temp_file = f"{input_file}.tmp"
            temp_files.append(temp_file)
            with open(temp_file, 'w') as temp:
                temp.write('\n'.join(sorted_chunk))

    # Step 2: Merge the sorted chunks
    with open(output_file, 'w') as outfile:
        chunks = [open(temp_file, 'r') for temp_file in temp_files]
        heap = []

        # Fill the heap with the first line from each chunk
        for index, chunk in enumerate(chunks):
            line = chunk.readline().strip()
            if line:
                heapq.heappush(heap, (line, index))

        while heap:
            value, index = heapq.heappop(heap)
            outfile.write(f"{value}\n")
            next_line = chunks[index].readline().strip()
            if next_line:
                heapq.heappush(heap, (next_line, index))

    # Step 3: Clean up temporary files
    for temp_file in temp_files:
        os.remove(temp_file)