extends PanelContainer

@onready var sidebar = $"Partition/SideBar"
@onready var partition = $"Partition"


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	# Center the scroll bar to window size, and disables sidebar's dragger.
	partition.set_split_offset(int(get_window().size.x * 0.25))
	sidebar.set_split_offset(get_window().size.y * 0.85)
	sidebar.dragging_enabled = false
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	# Locks the buttons on the sidebar.
	sidebar.set_split_offset(get_window().size.y * 0.85)
