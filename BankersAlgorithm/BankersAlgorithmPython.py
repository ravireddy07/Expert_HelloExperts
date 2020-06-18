from string import ascii_uppercase

letters = list(ascii_uppercase)

def main():
	available_instance = []
	origin_available_instance = []
	process = []

	total_allocation = []
	total_resources = []

	# f(x1)
	number_of_resources = int(input("Enter number of resources: "))
	size = int(input("Enter number of processes: "))

	# f(x2)
	total_resources = set_total_resources(number_of_resources=number_of_resources)

	# f(x3)
	process = set_processes(number_of_resources=number_of_resources, size=size)
	total_allocation = get_total_allocation(process=process, size=len(process), number_of_resources=number_of_resources)
	available_instance = get_available_instance(total_resources=total_resources, total_allocation=total_allocation, number_of_resources=number_of_resources)
	origin_available_instance = list(available_instance)
	
	# f(x4)
	process = get_process_need(process=process, size=len(process), number_of_resources=number_of_resources)

	temp = list(process)

	# f(x5)
	while (len(process) != 0):
		queue, process = compare_ai_need(available_instance=available_instance, process=process, size=len(process), number_of_resources=number_of_resources)
		# f(x6)
		available_instance = get_new_ai(available_instance=available_instance, queue=queue, size=len(queue), number_of_resources=number_of_resources)
	
	# f(x7)
	is_safe, available_instance = check_safety(origin_available_instance=origin_available_instance, available_instance=available_instance, total_allocation=total_allocation, number_of_resources=number_of_resources)
	
	process = list(temp)

	print("Total Resources : {}".format(total_resources))
	print("Total Allocation : {}".format(total_allocation))
	print("Original Available Instance : {}".format(origin_available_instance))
	print("New Available Instance : {}".format(available_instance))
	print("Processes : {}".format(process))
	print("Safe" if is_safe == True else "Not Safe")

def set_total_resources(number_of_resources=0):
	total_resources = []
	for resource_number in range(0, number_of_resources):
		total_resources.append(int(input("Total Resources, value for {}: ".format(letters[resource_number]))))
	return total_resources

def set_processes(number_of_resources=0, size=0):
	cur_allocation = []
	max_allocation = []
	process = []
	for index in range(0, size):
		for resource_number in range(0, number_of_resources):			
			max_allocation.append(int(input("Max. Allocation #{}, value for {}: ".format(index + 1, letters[resource_number]))))
		for resource_number in range(0, number_of_resources):			
			cur_allocation.append(int(input("Cur. Allocation #{}, value for {}: ".format(index + 1, letters[resource_number]))))
		process.append([max_allocation, cur_allocation])
		max_allocation = []
		cur_allocation = []
	return process

def get_total_allocation(process=[], size=0, number_of_resources=0):
	summation = 0
	total_allocation = []
	for resource_number in range(0, number_of_resources):
		for index in range(0, size):
			summation += process[index][1][resource_number]
		total_allocation.append(summation)
		summation = 0
	return total_allocation

def get_available_instance(total_resources=[], total_allocation=[], number_of_resources=0):
	available_instance = list([abs(rn_total_resources - rn_total_allocation) for rn_total_resources, rn_total_allocation in zip(total_resources, total_allocation)])
	return available_instance

def get_process_need(process=[], size=0, number_of_resources=0):
	for index in range(0, size):
		need = list([abs(rn_max_alloc - rn_current_alloc) for index, rn_max_alloc, rn_current_alloc in zip(process, process[index][0], process[index][1])])
		process[index].append(need)
		need = []
	return process

def compare_ai_need(available_instance=[], process=[], size=0, number_of_resources=0):
	for_removal = []
	queue = []
	for index in range(0, size):
		if (process[index][2] < available_instance):
			queue.append([process[index][2], process[index][0]])
			for_removal.append(process[index])
	queue.sort()
	for index in range(0, len(for_removal)):
		process.remove(for_removal[index])
	return queue, process

def get_new_ai(available_instance=[], queue=[], size=0, number_of_resources=0):
	for index in range(0, size):
		for resource_number in range(0, number_of_resources):
			available_instance[resource_number] = abs(available_instance[resource_number] - queue[index][0][resource_number]) + queue[index][1][resource_number]
	return available_instance

def check_safety(origin_available_instance=[], available_instance=[], total_allocation=[], number_of_resources=0):
	available_instance = list([abs(rn_available_instance - rn_total_allocation) for rn_available_instance, rn_total_allocation in zip(available_instance, total_allocation)])
	return (True if (origin_available_instance == available_instance) else False), available_instance

if __name__ == '__main__':
	main()
